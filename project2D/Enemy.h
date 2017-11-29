#pragma once
#include "Laser.h"
class Enemy : public Entity
{
public:
	bool mIsAlive;
	Enemy();
	/*Prototype:Enemy();
	Description: The constructor for the enemy class
	Arguments : None.
	Precondition : None.
	Postcondition : An enemy is created.
	Protection : Public.*/
	~Enemy();
	/*Prototype:~Enemy();
	Description: The destructor for the enemy class
	Arguments : None.
	Precondition : None.
	Postcondition : An enemy is deleted.
	Protection : Public.*/
	void Move(float timer);
  /*Prototype:void Move(float timer);
	Description: Changes the enemy's mPosition so they move in a straight line downward.
	Arguments : A timer
	Precondition : The enemy's position is static and unchanging
	Postcondition : The enemy will move downward.
	Protection : Public.*/
	void LaserCheck(Laser *laser,int lasernum);
	/*Prototype:void LaserCheck(Laser *laser,int lasernum);
	Description: Checks to see if a laser is colliding with an enemy
	Arguments : The laser being checked and the number of lasers fired so far.
	Precondition : None.
	Postcondition : The enemy will be deleted if the laser collidies with it
	Protection : Public.*/
};