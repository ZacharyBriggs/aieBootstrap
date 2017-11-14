#include "Laser.h"
Laser::Laser()
{
	mPos.mY = 100;
	mPos.mX = 640;
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
void Laser::Draw(aie::Renderer2D * rend,float timer,Entity *player, aie::Texture *laser)
{
	rend->setRenderColour(0, 0, 1, 1);
	rend->drawSprite(laser,player->mPos.mX, timer * mPos.mY + 100, mScale.mX, mScale.mY);
}