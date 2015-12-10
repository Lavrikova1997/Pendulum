#include "Const.h"
#include "Pendulum.h"
#include "Gearbox.h"

void process(Clock & clock, StatePendulum & state, Gearbox & gearSet, Pendulum & pendulum)
{
	Time timer = clock.getElapsedTime();
	float time = timer.asSeconds();

	if (state == Pendulum_Left)
	{
		RotatePendulum(pendulum, time, state);
		if (time < PENDULUM_PERIOD - STOPPED_GEARS_TIME)
		{
			rotateGears(gearSet);
		}
		if (time > PENDULUM_PERIOD)
		{
			PendulumSetAngle(pendulum, MAX_ANGLE);
			state = Pendulum_Rigth;
			clock.restart();
		}
	}
	else if (state == Pendulum_Rigth)
	{
		RotatePendulum(pendulum, time, state);
		if (time > STOPPED_GEARS_TIME && time < PENDULUM_PERIOD - STOPPED_GEARS_TIME)
		{
			rotateGears(gearSet);
		}
		if (time > PENDULUM_PERIOD)
		{
			PendulumSetAngle(pendulum, -MAX_ANGLE);
			state = Pendulum_Left;
			clock.restart();
		}
	}
}

int main()
{
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(500, 600), "Pendulum", Style::Default, settings);
	
	Texture gearTexture;
	Texture pendulumGearTexture;
	gearTexture.loadFromFile("gear.png");
	pendulumGearTexture.loadFromFile("pendulumGear.png");
	
	Gearbox gearSet;
	iniGearbox(gearSet, gearTexture, pendulumGearTexture);

	Pendulum pendulum;
	iniPendulum(pendulum);
	
	Clock clock;
	StatePendulum statePendulum = Pendulum_Left;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		process(clock, statePendulum, gearSet, pendulum);

		window.clear();

		DrawPendulum(pendulum, window);
		DrawGearbox(gearSet, window);

		window.display();
	}

	dispPendulum(pendulum);
	dispGearbox(gearSet);

	return 0;
}