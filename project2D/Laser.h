#pragma once
#include "Entity.h"
class Laser : public Entity
{
public:
	bool mIsFired;
	Laser();
	~Laser();
	void Fire(int x,int y);
	void Update(float timer);
};