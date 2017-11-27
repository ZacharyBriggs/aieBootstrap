#pragma once
#include "Entity.h"
#include <Renderer2D.h>
class Laser : public Entity
{
public:
	Laser();
	~Laser();
	bool mIsFired;
	//Sets the laser to fired and assigns it's position.
	void Fire(Vector2 pos);
	//Changes the lasers position constantly so it can move foward
	void Update(float timer);
};