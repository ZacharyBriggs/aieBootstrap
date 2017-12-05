#include "Player.h"
Player::Player()
{
	mPos.mX = 640;
	mPos.mY = 100;
	mScale.mX = 60;
	mScale.mY = 60;
	mIsAlive = true;
}
Player::~Player()
{
}

void Player::LaserCheck(Laser * laser, int lasernum)
{
	for (int i = 0; i < lasernum; i++)
	{
		if (laser[i].mPos.mX > mPos.mX - (mScale.mX / 2) && laser[i].mPos.mX < mPos.mX + (mScale.mX / 2))
		{
			if (laser[i].mPos.mY > mPos.mY - mScale.mY && laser[i].mPos.mY < mPos.mY + mScale.mY)
			{
				mIsAlive = false;
				mPos.mY = 10000;
				laser[i].mIsFired = false;
				laser[i].mPos.mX = 1000;
				laser[i].mPos.mY = 1000;
			}
		}
	}
}
