#include "Laser.h"

Laser::Laser()
{
	mPos.mY = 100;
	mPos.mX = 100;
	mScale.mX = 10;
	mScale.mY = 25;
}
Laser::~Laser()
{
}
void Laser::Draw(aie::Renderer2D * rend,float timer,Entity *player, aie::Texture *laser)
{
	rend->setRenderColour(0, 0, 1, 1);
	rend->drawSprite(laser,player->mPos.mX, timer * mPos.mY + 100, mScale.mX, mScale.mY);
}