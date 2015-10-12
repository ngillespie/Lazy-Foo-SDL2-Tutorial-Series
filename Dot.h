#pragma once

#include <SDL2/SDL.h>

#include "OTexture.h"

class Dot
{
public:
	//The dimensions of the dot
	static const int DOT_WIDTH = 20;
	static const int DOT_HEIGHT = 20;

	//Maximum axis velocity of the dot
	static const int DOT_VEL = 10;

	//Initialize the variables
	Dot(int screen_width = 100, int screen_height = 100);

	//Takes key presses and adjusts the dot's velocity
	void handleEvent(SDL_Event& e);

	//Moves the dot
	void move();

	//Shows the dot on the screen
	void render(OTexture *dotTexture);

private:
	//The X and Y offset of the dot
	int mPosX, mPosY;

	//The velocity of the dot
	int mVelX, mVelY;

	//Screen size to keep dot in box
	int mScreenWidth, mScreenHeight;
};