#include "Dot.h"

Dot::Dot(int levelWidth, int levelHeight)
{
	//Initialize of Offsets
	mPosX = 0;
	mPosY = 0;


	//Initialize the velocity
	mVelX = 0;
	mVelY = 0;

	mLevelWidth = levelWidth;
	mLevelHeight = levelHeight;
}

void Dot::handleEvent(SDL_Event &e)
{
	//If a key was pressed
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: mVelY -= DOT_VEL; break;
		case SDLK_DOWN: mVelY += DOT_VEL; break;
		case SDLK_LEFT: mVelX -= DOT_VEL; break;
		case SDLK_RIGHT: mVelX += DOT_VEL; break;
		}//end key sym swithc
	}//end if key down
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: mVelY += DOT_VEL; break;
		case SDLK_DOWN: mVelY -= DOT_VEL; break;
		case SDLK_LEFT: mVelX += DOT_VEL; break;
		case SDLK_RIGHT: mVelX -= DOT_VEL; break;
		}//end key sym swithc
	}//end else if key up
}//end handle event method

void Dot::move()
{
	//Move the dot left or right
	mPosX += mVelX;

	//If the dot went to far to hte left or right
	if ((mPosX < 0) || (mPosX + DOT_WIDTH > mLevelWidth))
	{
		//Move back
		mPosX -= mVelX;
	}

	//Move the dot up or down
	mPosY += mVelY;

	//If the dot went to far to up or down
	if ((mPosY < 0) || (mPosY + DOT_HEIGHT > mLevelHeight))
	{
		//Move back
		mPosY -= mVelY;
	}
}// end move method 

void Dot::render(OTexture& dotTexture)
{
	//Show the dot
	dotTexture.render(mPosX, mPosY);
}//end render method

int Dot::getPosX()
{
	return mPosX;
}

int Dot::getPosY()
{
	return mPosY;
}