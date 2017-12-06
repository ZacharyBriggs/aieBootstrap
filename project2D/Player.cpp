#include "Player.h"

Player::Player()
{
	mX = 640;
	mY = 360;
	mScaleX = 100;
	mScaleY = 100;
	mSpeed = 500.0f;
	mIsAlive = true;
}
Player::~Player()
{
}
void Player::LaserCheck(Laser * laser, int lasernum)
{
	for (int i = 0; i < lasernum; i++)
	{
		if (laser[i].mX > mX - (mScaleX / 2) && laser[i].mX < mX + (mScaleX / 2))
		{
			if (laser[i].mY > mY - mScaleY && laser[i].mY < mY + mScaleY)
			{
				mIsAlive = false;
				mY = 10000;
				laser[i].mIsFired = false;
				laser[i].mX = 1000;
				laser[i].mY = 1000;
			}
		}
	}
}