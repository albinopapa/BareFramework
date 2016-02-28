#pragma once

class RectI
{
public:
	RectI();
	RectI(int Left, int Top, int Width, int Height);
	int Right()const;
	int Bottom()const;
	bool operator==(const RectI &Other)const;

	int left, top, width, height;
};