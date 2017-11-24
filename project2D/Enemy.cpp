#include "Enemy.h"
Enemy::Enemy()
{
	mPos.mX = 0;
	mPos.mY = 0;
	mScale.mX = 50;
	mScale.mY = 50;
	mIsAlive = true;
}
Enemy::Enemy(float posX, float posY)
{
}
Enemy::~Enemy()
{
}
void Enemy::Move(float timer)
{
	mPos.mY -= 50.0f * timer;
}