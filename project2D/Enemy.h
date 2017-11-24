#pragma once
#include "Entity.h"
class Enemy : public Entity
{
public:
	bool mIsAlive;
	Enemy();
	Enemy(float posX, float posY);
	~Enemy();
	void Move(float timer);
};
