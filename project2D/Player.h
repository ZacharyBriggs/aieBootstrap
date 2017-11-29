#pragma once
#include "Entity.h"
class Player : public Entity
{
public:
	Player();
	/*Prototype:Player();
	Description: Constructor for player class.
	Arguments : None.
	Precondition : None.
	Postcondition : A Player is created.
	Protection : Public.*/
	~Player();
	/*Prototype: ~Player();
	Description: Deconstructor for player class.
	Arguments : None.
	Precondition : None.
	Postcondition : A Player is deleted.
	Protection : Public.*/
	bool mIsAlive;
};