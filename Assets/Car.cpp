#include "Car.h"

Car::Car()
{
}

Car::Car(int Px, int Py, D3DCOLOR BodyColor)
	:
	posX(Px),
	posY(Py),
	width(4),
	height(4),
	bodyColor(BodyColor),
	hLightColor(D3DCOLOR_XRGB(255, 255, 255)),
	tLightColor(D3DCOLOR_XRGB(255, 0, 0)),
	dir(Direction::Right)
{

}

RectI Car::GetRect() const
{
	return RectI(posX, posY, posX + width, posY + height);
}

void Car::Update(KeyboardClient & Kbd)
{
}

void Car::Draw(D3DGraphics & gfx)
{
	int lightWidth = 5;
	RectI leftHeadLight, rightHeadLight;
	RectI leftTailLight, rightTailLight;

	leftHeadLight.width = lightWidth;
	rightHeadLight.width = lightWidth;
	leftHeadLight.height = lightWidth;
	rightHeadLight.height = lightWidth;

	leftTailLight.width = lightWidth;
	rightTailLight.width = lightWidth;
	leftTailLight.height = lightWidth;
	rightTailLight.height = lightWidth;

	int pX = posX * 10;
	int pY = posY * 10;
	int w = width * 10;
	int h = height * 10;
	switch (dir)
	{
	case Direction::Up:
		leftHeadLight.left	= pX + 5;
		leftHeadLight.top	= pY;
		rightHeadLight.left = pX + lightWidth - 5;
		rightHeadLight.top	= pY;

		leftTailLight.left	= leftHeadLight.left;
		leftTailLight.top	= pY + lightWidth;
		rightTailLight.left = rightHeadLight.left;
		rightTailLight.top	= pY + lightWidth;
		break;
	case Direction::Right:
		leftHeadLight.left	= pX + h - lightWidth;
		leftHeadLight.top	= pY + 5;
		rightHeadLight.left = pX + h - lightWidth;
		rightHeadLight.top	= pY + w - lightWidth - 5;
		
		leftTailLight.left	= pX;
		leftTailLight.top	= leftHeadLight.top;
		rightTailLight.left = pX;
		rightTailLight.top	= rightHeadLight.top;
		break;
	case Direction::Down:
		leftTailLight.left	= pX + 5;
		leftTailLight.top	= pY;
		rightTailLight.left = pX + lightWidth - 5;
		rightTailLight.top	= pY;

		leftHeadLight.left	= leftHeadLight.left;
		leftHeadLight.top	= pY + lightWidth;
		rightHeadLight.left = rightHeadLight.left;
		rightHeadLight.top	= pY + lightWidth;
		break;
	case Direction::Left:
		leftTailLight.left	= pX + h - lightWidth;
		leftTailLight.top	= pY + 5;
		rightTailLight.left = pX + h - lightWidth;
		rightTailLight.top	= pY + w - lightWidth - 5;

		leftHeadLight.left	= pX;
		leftHeadLight.top	= leftHeadLight.top;
		rightHeadLight.left = pX;
		rightHeadLight.top	= rightHeadLight.top;
		break;
	default:
		break;
	}
	// Draw body
	gfx.DrawFilledRect(pX, pY, pX + w, pY + h, bodyColor);

	// Draw left head light
	gfx.DrawFilledRect(leftHeadLight.left, leftHeadLight.top,
		leftHeadLight.Right(), leftHeadLight.Bottom(), 
		hLightColor);

	// Draw right head light
	gfx.DrawFilledRect(rightHeadLight.left, rightHeadLight.top,
		rightHeadLight.Right(), rightHeadLight.Bottom(),
		hLightColor);
	
	// Draw left tail light
	gfx.DrawFilledRect(leftTailLight.left, leftTailLight.top,
		leftTailLight.Right(), leftTailLight.Bottom(), 
		tLightColor);
	
	// Draw right tail light
	gfx.DrawFilledRect(rightTailLight.left, rightTailLight.top,
		rightTailLight.Right(), rightTailLight.Bottom(),
		tLightColor);
}

void Car::GetPosition(int & Px, int & Py)
{
	Px = posX;
	Py = posY;
}
