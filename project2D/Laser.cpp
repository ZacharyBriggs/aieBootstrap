#include "Laser.h"
Laser::Laser()
{
}
Laser::~Laser()
{
}
void Laser::Fire(Vector2 pos)
{
	mIsAlive = true;
	mPos.mX = pos.mX;
	mPos.mY = pos.mY;
}
void Laser::Update(float timer)
{
	if (mIsAlive)
		mPos.mY += 500.0f * timer;
}
bool Laser::operator==(const Laser & h)
{
	return mIsAlive = h.mIsAlive;
}
