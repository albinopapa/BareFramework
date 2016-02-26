#include "Observer.h"

void Observer::Update(KeyboardClient & Kbd)
{
	car.Update();
}

void Observer::Draw(D3DGraphics & gfx)
{
	car.Draw(gfx);
}
