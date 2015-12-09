#include "Const.h"
#include "Pendulum.h"

void iniPendulum(Pendulum & pendulum)
{
	pendulum.ancor = new ConvexShape();
	pendulum.ancor->setPointCount(4);
	pendulum.ancor->setPoint(0, Vector2f(0 * PENDULUM_SIZE, 3.5 * PENDULUM_SIZE));
	pendulum.ancor->setPoint(1, Vector2f(4 * PENDULUM_SIZE, 0.5 * PENDULUM_SIZE));
	pendulum.ancor->setPoint(2, Vector2f(8 * PENDULUM_SIZE, 3.5 * PENDULUM_SIZE));
	pendulum.ancor->setPoint(3, Vector2f(4 * PENDULUM_SIZE, 0 * PENDULUM_SIZE));
	pendulum.ancor->setFillColor(Color::Red);
	pendulum.ancor->setOrigin(Vector2f(4 * PENDULUM_SIZE, 0 * PENDULUM_SIZE));
	pendulum.ancor->setPosition(PENDULUM_POSITION);

	pendulum.line = new RectangleShape;
	pendulum.line->setSize((Vector2f(5, 15 * PENDULUM_SIZE)));
	pendulum.line->setOutlineColor(Color::Red);
	pendulum.line->setFillColor(Color::Red);
	pendulum.line->setOrigin(Vector2f(2.5, 0 * PENDULUM_SIZE));
	pendulum.line->setPosition(PENDULUM_POSITION);

	pendulum.body = new ConvexShape;
	pendulum.body->setPointCount(4);
	pendulum.body->setPoint(0, Vector2f(0.5 * PENDULUM_SIZE, 15 * PENDULUM_SIZE));;
	pendulum.body->setPoint(1, Vector2f(1 * PENDULUM_SIZE, 16 * PENDULUM_SIZE));
	pendulum.body->setPoint(2, Vector2f(1.5 * PENDULUM_SIZE, 15 * PENDULUM_SIZE));
	pendulum.body->setPoint(3, Vector2f(1 * PENDULUM_SIZE, 14 * PENDULUM_SIZE));
	pendulum.body->setOutlineColor(Color::Red);
	pendulum.body->setFillColor(Color::Red);
	pendulum.body->setOrigin(Vector2f(1 * PENDULUM_SIZE, 0 * PENDULUM_SIZE));
	pendulum.body->setPosition(PENDULUM_POSITION);

	pendulum.tooth1 = new ConvexShape;
	pendulum.tooth1->setPointCount(3);
	pendulum.tooth1->setPoint(0, Vector2f(0 * PENDULUM_SIZE, 3.5 * PENDULUM_SIZE));
	pendulum.tooth1->setPoint(1, Vector2f(0.5 * PENDULUM_SIZE, 4.5 * PENDULUM_SIZE));;
	pendulum.tooth1->setPoint(2, Vector2f(0.5 * PENDULUM_SIZE, 3 * PENDULUM_SIZE));
	pendulum.tooth1->setFillColor(Color::Red);
	pendulum.tooth1->setOrigin(Vector2f(4 * PENDULUM_SIZE, 0 * PENDULUM_SIZE));
	pendulum.tooth1->setPosition(PENDULUM_POSITION);

	pendulum.tooth2 = new ConvexShape;
	pendulum.tooth2->setPointCount(3);
	pendulum.tooth2->setPoint(0, Vector2f(8 * PENDULUM_SIZE, 3.5 * PENDULUM_SIZE));
	pendulum.tooth2->setPoint(1, Vector2f(7.5 * PENDULUM_SIZE, 4.5 * PENDULUM_SIZE));;
	pendulum.tooth2->setPoint(2, Vector2f(7.5 * PENDULUM_SIZE, 3 * PENDULUM_SIZE));
	pendulum.tooth2->setFillColor(Color::Red);
	pendulum.tooth2->setOrigin(Vector2f(4 * PENDULUM_SIZE, 0 * PENDULUM_SIZE));
	pendulum.tooth2->setPosition(PENDULUM_POSITION);
}

void PendulumSetAngle(Pendulum & pendulum, float angle)
{
	pendulum.ancor->setRotation(angle);
	pendulum.body->setRotation(angle);
	pendulum.tooth1->setRotation(angle);
	pendulum.tooth2->setRotation(angle);
	pendulum.line->setRotation(angle);
}

void RotatePendulum(Pendulum & pendulum, float time, StatePendulum state)
{
	if (state == Pendulum_Left)
	{
		PendulumSetAngle(pendulum, -MAX_ANGLE);
		pendulum.ancor->rotate(ANGLE_FREQURANCY * time);
		pendulum.body->rotate(ANGLE_FREQURANCY * time);
		pendulum.tooth1->rotate(ANGLE_FREQURANCY * time);
		pendulum.tooth2->rotate(ANGLE_FREQURANCY * time);
		pendulum.line->rotate(ANGLE_FREQURANCY * time);
	}
	else
	{
		PendulumSetAngle(pendulum, MAX_ANGLE);
		pendulum.ancor->rotate(-ANGLE_FREQURANCY * time);
		pendulum.body->rotate(-ANGLE_FREQURANCY * time);
		pendulum.tooth1->rotate(-ANGLE_FREQURANCY * time);
		pendulum.tooth2->rotate(-ANGLE_FREQURANCY * time);
		pendulum.line->rotate(-ANGLE_FREQURANCY * time);
	}
}

void DrawPendulum(Pendulum & pendulum, RenderWindow & window)
{
	window.draw(*pendulum.ancor);
	window.draw(*pendulum.body);
	window.draw(*pendulum.tooth1);
	window.draw(*pendulum.tooth2);
	window.draw(*pendulum.line);
}

void dispPendulum(Pendulum & pendulum)
{
	delete pendulum.ancor;
	delete pendulum.body;
	delete pendulum.tooth1;
	delete pendulum.tooth2;
	delete pendulum.line;
}
