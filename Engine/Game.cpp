/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
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
// Game Created by Alex Meyer
#include "MainWindow.h"
#include "Game.h"


Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	title.Play();
	player.Init(5, 370, 1, 0);
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (!isStarted)
	{
		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			isStarted = true;
		}

	}
	else
	{
		if (wnd.kbd.KeyIsPressed(VK_ESCAPE) && !paused)
		{
			paused = true;
		}
		else if (wnd.kbd.KeyIsPressed(VK_ESCAPE) && paused)
		{
			paused = false;
		}
		title.StopAll();
		player.Update();
		if (!isMainPlaying && !paused)
		{
			main.Play();
			isMainPlaying = true;
		}
		if (paused)
		{
			main.StopOne();
			isMainPlaying = false;
		}
		
	}
	if (isEnded)
	{
		main.StopAll();
		isStarted = false;
	}
}

void Game::ComposeFrame()
{
	if (isStarted)
	{
		player.Draw(5, 370, gfx);
		map.DrawSky(gfx);
		for (int x = 1; x < 799; x++)
		{
			map.DrawGround(x,400, gfx);
		}
	}
	else
	{

	}
}
