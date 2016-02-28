/****************************************************************************************** 
 *	Chili DirectX Framework Version 11.12.17											  *	
 *	D3DGraphics.cpp																		  *
 *	Copyright 2011 PlanetChili.net														  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "D3DGraphics.h"
#include <assert.h>

UINT D3DGraphics::scrWidth = 600;
UINT D3DGraphics::scrHeight = 600;

D3DGraphics::D3DGraphics( HWND hWnd )
{
	pDirect3D = Direct3DCreate9( D3D_SDK_VERSION );

    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory( &d3dpp,sizeof( d3dpp ) );
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;
	d3dpp.Flags = D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;

    pDirect3D->CreateDevice( D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL,hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_PUREDEVICE,&d3dpp,&pDevice );
	
	rect = D3DLOCKED_RECT{};

	pDevice->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &pBackBuffer);
	pSysBuffer.reset(new D3DCOLOR[scrWidth * scrHeight]);
}

D3DGraphics::~D3DGraphics()
{
}

void D3DGraphics::PutPixel( int x,int y,int r,int g,int b )
{
	assert(x >= 0 && x < scrWidth);
	assert(y >= 0 && y < scrHeight);
	pSysBuffer[x + y * scrWidth] = D3DCOLOR_XRGB(r, g, b);
}

void D3DGraphics::PutPixel(int x, int y, D3DCOLOR Color)
{
	assert(x >= 0 && x < scrWidth);
	assert(y >= 0 && y < scrHeight);
	pSysBuffer[x + (y * scrWidth)] = Color;
}

void D3DGraphics::BeginFrame()
{
	ZeroMemory(pSysBuffer.get(), sizeof(D3DCOLOR)*scrWidth*scrHeight);
}

void D3DGraphics::EndFrame()
{
	pBackBuffer->LockRect(&rect, NULL, NULL);

	int pitch = sizeof(D3DCOLOR) * scrWidth;
	int vidPitch = rect.Pitch >> 2;
	
	for (D3DCOLOR *pSysIter = pSysBuffer.get(), 
		*pVidIter = (D3DCOLOR *)rect.pBits,
		*end = &pSysBuffer[scrWidth * scrHeight]; pSysIter < end; 
		pSysIter += scrWidth, pVidIter += vidPitch)
	{		
		memcpy(pVidIter, pSysIter, pitch);
	}

	pBackBuffer->UnlockRect();
	pDevice->Present( NULL,NULL,NULL,NULL );
}

void D3DGraphics::DrawLine(int StartX, int StartY, int EndX, int EndY, 
	D3DCOLOR Color)
{
	StartX = max(0, min(scrWidth - 1, StartX));
	EndX = max(0, min(scrWidth - 1, EndX));
	StartY = max(0, min(scrHeight - 1, StartY));
	EndY = max(0, min(scrHeight - 1, EndY));

	int dx = EndX - StartX;
	int dy = EndY - StartY;

	float len = sqrt(pow(dx, 2) + pow(dy, 2));
	float invLen = 1.0f / len;
	float nx = dx * invLen;
	float ny = dy * invLen;

	for (int i = 0; i <= len; ++i)
	{
		PutPixel(StartX + (nx * i), StartY + (ny * i), Color);
	}
}

void D3DGraphics::DrawFilledRect(int Left, int Top, int Right, int Bottom, 
	D3DCOLOR Color)
{
	for (int y = Top; y < Bottom; ++y)
	{
		DrawLine(Left, y, Right, y, Color);
	}
}

void D3DGraphics::DrawRectOutline(int Left, int Top, int Right, int Bottom,
	D3DCOLOR Color)
{
	DrawLine(Left, Top, Right, Top, Color);
	DrawLine(Left, Bottom, Right, Bottom, Color);
	DrawLine(Left, Top, Left, Bottom, Color);
	DrawLine(Right, Top, Right, Bottom, Color);
}



