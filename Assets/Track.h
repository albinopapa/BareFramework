#pragma once
#include "D3DGraphics.h"
#include "RectI.h"
class Track
{
public:
	Track(int TrackWidth, int TrackHeight, int CellWidth);
	
	RectI GetTopLeftCorner()const;
	RectI GetTopRightCorner()const;
	RectI GetBottomLeftCorner()const;
	RectI GetBottomRightCorner()const;
	void Draw(D3DGraphics &gfx);

private:
	int width, height, cellWidth;
	D3DCOLOR wallColor, trackColor, fieldColor;
};