#pragma once
#include "D3DGraphics.h"
#include "Keyboard.h"
#include "RectI.h"

enum class Direction
{
	Up, Right, Down, Left
};
class Car
{
public:
	Car();
	Car(int Px, int Py, D3DCOLOR BodyColor);
	RectI GetRect()const;
	void Update(KeyboardClient &Kbd);
	void Draw(D3DGraphics &gfx);
	void GetPosition(int &Px, int &Py);

private:
	D3DCOLOR bodyColor, hLightColor, tLightColor;
	int posX, posY, width, height;
	Direction dir;
};