#pragma once
#include "Entity.h"
class Weapon :public Entity
{
public:
	Weapon();
	Weapon(float posX,float posY);
	~Weapon();
};