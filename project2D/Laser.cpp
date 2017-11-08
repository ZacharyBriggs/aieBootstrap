#include "Laser.h"

Laser::Laser()
{
	mPos.mY = 100;
}
Laser::~Laser()
{
}
void Laser::Draw(aie::Renderer2D * rend,float timer,Entity *player, aie::Texture *laser)
{
	rend->setRenderColour(0, 0, 1, 1);
	rend->drawSprite(laser,player->mPos.mX, timer * mPos.mY + 100, 25, 25);
}