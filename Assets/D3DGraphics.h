/****************************************************************************************** 
 *	Chili DirectX Framework Version 11.12.17											  *	
 *	D3DGraphics.h																		  *
 *	Copyright 2011 PlanetChili <http://www.planetchili.net>								  *
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
#pragma once
#include <wrl.h>
#include <memory>
#include <d3d9.h>

class D3DGraphics
{
public:
	D3DGraphics( HWND hWnd );
	~D3DGraphics();
	void PutPixel( int x,int y,int r,int g,int b );
	void PutPixel(int x, int y, D3DCOLOR Color);
	void BeginFrame();
	void EndFrame();

	void DrawLine(int StartX, int StartY, int EndX, int EndY, D3DCOLOR Color);
	void DrawFilledRect(int Left, int Top, int Right, int Bottom, D3DCOLOR Color);
	void DrawRectOutline(int Left, int Top, int Right, int Bottom, D3DCOLOR Color);

	static UINT scrWidth, scrHeight;
private:
	Microsoft::WRL::ComPtr<IDirect3D9>			pDirect3D;
	Microsoft::WRL::ComPtr<IDirect3DDevice9>	pDevice;
	Microsoft::WRL::ComPtr<IDirect3DSurface9>	pBackBuffer;
	D3DLOCKED_RECT		rect;
	std::unique_ptr<D3DCOLOR[]>					pSysBuffer;
};