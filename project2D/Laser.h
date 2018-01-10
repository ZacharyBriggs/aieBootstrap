#pragma once
#include "Entity.h"
class Laser : public Entity
{
	Laser();
	~Laser();
	void Fire(Vector2 pos);
	void Update(float timer);
};
