#pragma once
#include "Entity.h"
#include "Laser.h"
class Player : public Entity
{
public:
	Player();
	~Player();
	Laser Shoot();
};