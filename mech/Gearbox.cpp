#include "Gearbox.h"
#include "Const.h"

void iniGearbox(Gearbox & gearbox, Texture & gearTexture, Texture & pendulumGearTexture)
{
	gearbox.gear1 = new RectangleShape(Vector2f(10 * GEAR_SIZE, 10 * GEAR_SIZE));
	gearbox.gear2 = new RectangleShape(Vector2f(10 * GEAR_SIZE, 10 * GEAR_SIZE));
	gearbox.gearPendulum = new RectangleShape(Vector2f(15 * GEAR_SIZE, 15 * GEAR_SIZE));

	gearbox.gear1->setTexture(&gearTexture);
	gearbox.gear1->setOrigin(5 * GEAR_SIZE, 5 * GEAR_SIZE);
	gearbox.gear1->setPosition(5 * GEAR_SIZE, 5 * GEAR_SIZE);

	gearbox.gear2->setTexture(&gearTexture);
	gearbox.gear2->setOrigin(5 * GEAR_SIZE, 5 * GEAR_SIZE);
	gearbox.gear2->setPosition(11.5 * GEAR_SIZE, 11.5 * GEAR_SIZE);

	gearbox.gearPendulum->setTexture(&pendulumGearTexture);
	gearbox.gearPendulum->setOrigin(7.5 * GEAR_SIZE, 7.5 * GEAR_SIZE);
	gearbox.gearPendulum->setPosition(11.5 * GEAR_SIZE, 11.5 * GEAR_SIZE);
}

void rotateGears(Gearbox & gearbox)
{
	gearbox.gear1->rotate(GEARS_ROTATE);
	gearbox.gear2->rotate(-GEARS_ROTATE);
	gearbox.gearPendulum->rotate(-GEARS_ROTATE);
}

void DrawGearbox(Gearbox & gearbox, RenderWindow & window)
{
	window.draw(*gearbox.gearPendulum);
	window.draw(*gearbox.gear1);
	window.draw(*gearbox.gear2);
}

void dispGearbox(Gearbox & gearbox)
{
	delete gearbox.gear1;
	delete gearbox.gear2;
	delete gearbox.gearPendulum;
}