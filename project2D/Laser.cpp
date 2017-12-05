#include "Laser.h"
Laser::Laser()
{
	int mX = 0;
	int mY = 0;
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
}