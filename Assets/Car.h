#pragma once
#include "D3DGraphics.h"
#include "Keyboard.h"


class Car
{
public:
	Car();
	Car(int Px, int Py, D3DCOLOR BodyColor);
	void Update(KeyboardClient &Kbd);
	void Draw(D3DGraphics &gfx);
	void GetPosition(int &Px, int &Py);

private:
	D3DCOLOR bodyColor, hLightColor, tLightColor;
	int posX, posY;
	unsigned int direction;
	const unsigned int dirUp = 0;
	const unsigned int dirRight = 1;
	const unsigned int dirDown = 2;
	const unsigned int dirLeft = 3;
};