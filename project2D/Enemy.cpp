#include "Enemy.h"
Enemy::Enemy()
{
	mPos.mX = 0;
	mPos.mY = 0;
	mScale.mX = 50;
	mScale.mY = 50;
	mIsAlive = true;
}
Enemy::~Enemy()
{
}
void Enemy::Move(float timer)
{
	mPos.mY -= 50.0f * timer;
}
void Enemy::LaserCheck(Laser *laser,int lasernum)
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
			}
		}
	}
}