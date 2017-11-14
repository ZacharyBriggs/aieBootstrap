#include "Boundary.h"
Boundary::Boundary(int xPos)
{
	mPos.mX = xPos;
	mPos.mY = 0;
	mScale.mX = 0;
	mScale.mY = 720;
}
Boundary::~Boundary()
{
}
