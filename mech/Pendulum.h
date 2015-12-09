#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

enum StatePendulum { Pendulum_Left, Pendulum_Rigth };

struct Pendulum
{
	RectangleShape* line;
	ConvexShape* ancor;
	ConvexShape* body;
	ConvexShape* tooth1;
	ConvexShape* tooth2;
};

void iniPendulum(Pendulum & pendulum);

void PendulumSetAngle(Pendulum & pendulum, float angle);

void RotatePendulum(Pendulum & pendulum, float time, StatePendulum state);

void DrawPendulum(Pendulum & pendulum, RenderWindow & window);

void dispPendulum(Pendulum & pendulum);
