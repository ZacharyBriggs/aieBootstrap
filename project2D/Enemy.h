#pragma once
#include "Entity.h"
#include "Weapon.h"
class Enemy : public Entity
{
public:
	bool mIsAlive;
	Enemy();
	Enemy(float posX, float posY);
	~Enemy();
	void Fire();
	void Move(float timer);
	void DropWeapon();
};
