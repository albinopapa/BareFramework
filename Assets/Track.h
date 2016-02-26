#pragma once
#include "D3DGraphics.h"

class Track
{
public:
	Track(int TrackWidth, int TrackHeight, int CellWidth);

	void Draw(D3DGraphics &gfx);

private:
	int width, height, cellWidth;
	D3DCOLOR wallColor, trackColor, fieldColor;
};