#pragma once
#include "Entity.h"
#include "Laser.h"
class Player : public Entity
{
public:
	bool mIsAlive;
	Player();
	~Player();
	void LaserCheck(Laser *laser, int lasernum);
};