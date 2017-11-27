#pragma once
#include "Entity.h"
class Player : public Entity
{
public:
	Player();
	~Player();
	bool mIsAlive;
	void Move(float timer);
};