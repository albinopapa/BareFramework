#include "Track.h"

Track::Track(int TrackWidth, int TrackHeight, int CellWidth)
	:
	width(TrackWidth),
	height(TrackHeight),
	cellWidth(CellWidth)
{
	wallColor = D3DCOLOR_XRGB(255, 0, 0);
	trackColor = D3DCOLOR_XRGB(95, 95, 95);
	fieldColor = D3DCOLOR_XRGB(23, 191, 31);
}

RectI Track::GetTopLeftCorner() const
{
	return RectI(1, 1, 4, 4);
}

RectI Track::GetTopRightCorner() const
{
	return RectI(55, 1, 4, 4);
}

RectI Track::GetBottomLeftCorner() const
{
	return RectI(1, 55, 4, 4);
}

RectI Track::GetBottomRightCorner() const
{
	return RectI(55, 55, 4, 4);
}

void Track::Draw(D3DGraphics & gfx)
{
	int pixWidth = (width * cellWidth);
	int pixHeight = (height * cellWidth);

	for (int i = 0; i < cellWidth; ++i)
	{
		int innerWallOffsetStart = i + 50;
		int innerWallOffsetEnd = pixWidth - i - 50;
		// Outer wall
		gfx.DrawRectOutline(i, i, pixWidth - i, pixHeight - i, wallColor);
		// Inner wall
		gfx.DrawRectOutline(innerWallOffsetStart, innerWallOffsetStart,
			innerWallOffsetEnd, innerWallOffsetEnd, wallColor);
	}

	// Draw track
	for (int i = 10; i < 50; ++i)
	{
		gfx.DrawRectOutline(i, i, pixWidth - i, pixHeight - i, trackColor);
	}

	// Draw field in the middle
	gfx.DrawFilledRect(60, 60, pixWidth - 60, pixHeight - 60, fieldColor);

}
