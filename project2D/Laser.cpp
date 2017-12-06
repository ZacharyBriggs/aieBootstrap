#include "Laser.h"
Laser::Laser()
{
	int mX = 0;
	int mY = 0;
	mScaleX = 20;
	mScaleY = 20;
	mIsFired = false;
}
Laser::~Laser()
{
}
void Laser::Fire(int x, int y)
{
	mIsFired = true;
	mX = x;
	mY = y;
}
void Laser::Update(float timer)
{
	if (mIsFired)
		mY += 500.0f*timer;
}