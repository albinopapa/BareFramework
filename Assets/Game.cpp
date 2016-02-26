/****************************************************************************************** 
 *	Chili DirectX Framework Version 11.12.17											  *	
 *	Game.cpp																			  *
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
#include "Game.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 100

float var = 0;

Game::Game( HWND hWnd,const KeyboardServer& kServer )
:	gfx ( hWnd ),
	kbd( kServer )
{
	srand( (unsigned int)time( NULL ) );
	for( int n = 0;n < 100;n++ )
	{
		star[n].p.x = rand() % 400;
		star[n].p.y = rand() % 300;
	}
}

void Game::Go()
{
	gfx.BeginFrame();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::DrawBeam( int x,int y )
{
	
	for( int a = 0 ; a < 254 ; a++ )
	{
		gfx.PutPixel( x,a + (int)var, 0,a + 1,0 );
	}
	var += 0.1f;
	if( (int)var > 250 )
	{
		var = 0.0f;
	}

}


void Game::ComposeFrame()
{
	for( int n1 = 0;n1 < N; n1++ )
	{		
		if(star[n1].p.y < 400)
		{	
			gfx.PutPixel( (int)star[n1].p.x, (int)star[n1].p.y, 255,215,0 );
			star[n1].p.x += rand() % 100 / 90;
			star[n1].p.y += rand() % 100 / 90;
		}

	}
	DrawBeam(100,200);
	DrawBeam(200,300);
	DrawBeam(300,500);
	DrawBeam(600,700);
	
}