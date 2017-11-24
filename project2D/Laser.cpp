#include "Laser.h"
Laser::Laser()
{
	mPos.mY = 0;
	mPos.mX = 0;
	mScale.mX = 10;
	mScale.mY = 25;
	mIsFired = false;
}
Laser::~Laser()
{
}
void Laser::Fire(Vector2 pos)
{
	mIsFired = true;
	mPos.mX = pos.mX;
	mPos.mY = pos.mY;
}
void Laser::Update(float timer)
{
	if(mIsFired)
		mPos.mY += 500.0f* timer;
}