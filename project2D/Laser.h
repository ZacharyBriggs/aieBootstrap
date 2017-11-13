#pragma once
#include "Entity.h"
#include <Renderer2D.h>
class Laser : public Entity
{
public:
	Laser();
	~Laser();
	bool mIsFired;
	void Draw(aie::Renderer2D *rend,float timer,Entity *player,aie::Texture *laser);
};