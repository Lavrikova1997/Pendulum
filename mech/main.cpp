#include "Const.h"
#include "Pendulum.h"

void iniGears(RectangleShape & gear1, RectangleShape & gear2, RectangleShape & gearPendulum,
	Texture & gearTexture, Texture & pendulumGearTexture)
{
		gear1.setTexture(&gearTexture);
		gear1.setOrigin(5 * GEAR_SIZE, 5 * GEAR_SIZE);
		gear1.setPosition(5 * GEAR_SIZE, 5 * GEAR_SIZE);

		gear2.setTexture(&gearTexture);
		gear2.setOrigin(5 * GEAR_SIZE, 5 * GEAR_SIZE);
		gear2.setPosition(11.5 * GEAR_SIZE, 11.5 * GEAR_SIZE);

		gearPendulum.setTexture(&pendulumGearTexture);
		gearPendulum.setOrigin(7.5 * GEAR_SIZE, 7.5 * GEAR_SIZE);
		gearPendulum.setPosition(11.5 * GEAR_SIZE, 11.5 * GEAR_SIZE);

}

void rotateGears(RectangleShape & gear1, RectangleShape & gear2, RectangleShape & gearPendulum)
{
		gear1.rotate(GEARS_ROTATE);
		gear2.rotate(-GEARS_ROTATE);
		gearPendulum.rotate(-GEARS_ROTATE);
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
	
	RectangleShape gear1(Vector2f(10 * GEAR_SIZE, 10 * GEAR_SIZE));
	RectangleShape gear2(Vector2f(10 * GEAR_SIZE, 10 * GEAR_SIZE));
	RectangleShape gearPendulum(Vector2f(15 * GEAR_SIZE, 15 * GEAR_SIZE));

	iniGears(gear1, gear2, gearPendulum, gearTexture, pendulumGearTexture);

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
		Time timer = clock.getElapsedTime();
		float time = timer.asSeconds();
	
		if (statePendulum == Pendulum_Left)
		{
			RotatePendulum(pendulum, time, statePendulum);
			if (time < PENDULUM_PERIOD - STOPPED_GEARS_TIME)
			{
				rotateGears(gear1, gear2, gearPendulum);
			}
			if (time > PENDULUM_PERIOD)
			{
				PendulumSetAngle(pendulum, MAX_ANGLE);
				statePendulum = Pendulum_Rigth;
				clock.restart();
			}
		}
		else if (statePendulum == Pendulum_Rigth)
		{
			RotatePendulum(pendulum, time, statePendulum);
			if (time > STOPPED_GEARS_TIME && time < PENDULUM_PERIOD - STOPPED_GEARS_TIME)
			{
				rotateGears(gear1, gear2, gearPendulum);
			}
			if (time > PENDULUM_PERIOD)
			{
				PendulumSetAngle(pendulum, -MAX_ANGLE);
				statePendulum = Pendulum_Left;
				clock.restart();
			}
		}

		window.clear();

		DrawPendulum(pendulum, window);
		window.draw(gearPendulum);
		window.draw(gear1);
		window.draw(gear2);

		window.display();
	}
	dispPendulum(pendulum);
	return 0;
}