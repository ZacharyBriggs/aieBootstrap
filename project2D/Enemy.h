#pragma once
#include "Entity.h"
#include "Laser.h"

class Enemy : public Entity
{
public:
	bool mIsAlive;
	Enemy();
	~Enemy();
	//Updates the enemy's position constantly so it may move foward
	void Move(float timer);
	//Checks if the enemy was hit by a laser
	void HitCheck(Laser *laser,int lasernum);
};
