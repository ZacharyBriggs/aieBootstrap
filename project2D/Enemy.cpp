#include "Enemy.h"
Enemy::Enemy()
{
	mPos.mX = 0;
	mPos.mY = 0;
	mScale.mX = 50;
	mScale.mY = 50;
	mIsAlive = true;
}
Enemy::Enemy(int posX, int posY)
{
}
Enemy::~Enemy()
{
}