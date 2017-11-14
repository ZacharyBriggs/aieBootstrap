#pragma once
#include "Entity.h"
class Enemy : public Entity
{
public:
	Enemy();
	Enemy(int posX, int posY);
	~Enemy();
	bool mIsAlive;
};
