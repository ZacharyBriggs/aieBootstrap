#pragma once
#include "Entity.h"
class Enemy : public Entity
{
public:
	bool mIsAlive;
	Enemy();
	Enemy(float posX, float posY);
	~Enemy();
	//Updates the enemy's position constantly so it may move foward
	void Move(float timer);
};
