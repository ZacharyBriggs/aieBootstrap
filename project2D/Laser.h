#pragma once
#include "Entity.h"
class Laser : public Entity
{
public:
	Laser();
	~Laser();
	void Fire(Vector2 pos);
	void Update(float timer);
	bool operator==(const Laser& h);
};
