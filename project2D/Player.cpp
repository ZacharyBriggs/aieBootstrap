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