#include "RectI.h"

RectI::RectI()
	:
	left(0), top(0), width(0), height(0)
{
}

RectI::RectI(int Left, int Top, int Width, int Height)
	:
	left(Left), top(Top), width(Width), height(Height)
{
}

int RectI::Right() const
{
	return left + width;
}

int RectI::Bottom() const
{
	return top + height;
}

bool RectI::operator==(const RectI & Other) const
{
	bool match = ((left == Other.left) && (top == Other.top) &&
		(Right() == Other.Right()) && (Bottom() == Other.Bottom()));
	return match;
}

