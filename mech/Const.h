#pragma once
#include <SFML/Graphics.hpp>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace sf;

static const int GEAR_SIZE = 20;
static const float GEARS_ROTATE = 0.015f;
static const float ANGLE_FREQURANCY = 20.f;
static const float MAX_ANGLE = ANGLE_FREQURANCY / 2.f;
static const float PENDULUM_PERIOD = 2.f / ANGLE_FREQURANCY * float(M_PI * M_PI);
static const float STOPPED_GEARS_TIME = PENDULUM_PERIOD * 0.107f;

static const int PENDULUM_SIZE = 35;
static const Vector2f PENDULUM_POSITION = Vector2f(12.425 * GEAR_SIZE, 0 * GEAR_SIZE);

