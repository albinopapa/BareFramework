#pragma once
#include "Car.h"
#include "Keyboard.h"

class Observer
{
public:
	Observer();

	void Update(KeyboardClient &Kbd);
	void Draw(D3DGraphics &gfx);

private:
	Car car;
};