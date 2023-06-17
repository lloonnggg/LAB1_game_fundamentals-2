#pragma once
#include <SDL.h>
#include <string>
#include <SDL_image.h>

class Player
{
public:
	int PlayerX;
	int PlayerY;
	int PlayerW;
	int PlayerH;
	int Velocity;
	int JumpVel;

	Player(int x, int y, int w, int h, int Vel, int JVel)
	{
		PlayerX = x;
		PlayerY = y;
		PlayerW = w;
		PlayerH = h;
		Velocity = Vel;
		JumpVel = JVel;
	}
};



