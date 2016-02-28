#include "Observer.h"

Observer::Observer()
	:
	car(1, 1, D3DCOLOR_XRGB(255, 0, 255)),
	track(60, 60, 10)
{
}

void Observer::Update(KeyboardClient & Kbd)
{
	car.Update(Kbd);
}

void Observer::Draw(D3DGraphics & gfx)
{
	track.Draw(gfx);
	car.Draw(gfx);
}
