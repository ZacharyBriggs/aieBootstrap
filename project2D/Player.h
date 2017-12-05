#pragma once
#include "Laser.h"
class Player : public Entity
{
public:
	bool mIsAlive;
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
	void LaserCheck(Laser *laser, int lasernum);
	/*Prototype:void LaserCheck(Laser *laser, int lasernum);
	Description: Checks to see if a laser is colliding with the player
	Arguments : The laser being checked and the number of lasers fired so far.
	Precondition : None.
	Postcondition : mIsAlive is set to false.
	Protection : Public.*/
};