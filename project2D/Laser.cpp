#include "Laser.h"
Laser::Laser()
{
	mPos.mY = -1000;
	mPos.mX = -1000;
	mScale.mX = 10;
	mScale.mY = 25;
	mIsFired = false;
}
Laser::~Laser()
{
}
void Laser::Fire(const Vector2 pos)
{
	mIsFired = true;
	mPos.mX = pos.mX;
	mPos.mY = pos.mY;
}
void Laser::Update(const float timer)
{
	if(mIsFired)
		mPos.mY += 500.0f* timer;
}