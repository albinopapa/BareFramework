#include "Track.h"

Track::Track(int TrackWidth, int TrackHeight, int CellWidth)
	:
	width(TrackWidth),
	height(TrackHeight),
	cellWidth(CellWidth)
{
}

void Track::Draw(D3DGraphics & gfx)
{
	for (int i = 0; i < cellWidth; ++i)
	{
		gfx.DrawRectOutline(i, i, (width * cellWidth) - i, (height * cellWidth) - i, wallColor);
	}

	gfx.DrawFilledRect(60, 60, (width * cellWidth) - 60, (height * cellWidth) - 60, fieldColor);

	for (int i = 10; i < 50; ++i)
	{

	}
}
