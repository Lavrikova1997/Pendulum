#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

struct Gearbox
{
	RectangleShape * gear1;
	RectangleShape * gear2;
	RectangleShape * gearPendulum;
};

void iniGearbox(Gearbox & gearbox, Texture & gearTexture, Texture & pendulumGearTexture);
void rotateGears(Gearbox & gearbox);
void DrawGearbox(Gearbox & gearbox, RenderWindow & window);
void dispGearbox(Gearbox & gearbox);