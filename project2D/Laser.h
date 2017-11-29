#pragma once
#include "Entity.h"
class Laser : public Entity
{
public:
	Laser();
	/*Prototype:Laser();
	Description: The constructor for the laser class
	Arguments : None.
	Precondition : None.
	Postcondition : A laser is created.
	Protection : Public.*/
	~Laser();
	/*Prototype:~Laser();
	Description: The destructor for the laser class
	Arguments : None.
	Precondition : None.
	Postcondition : A laser is deleted
	Protection : Public.*/
	bool mIsFired;
	void Fire(Vector2 pos);
	/*Prototype:void Fire(Vector2 pos);
	Description: Sets a laser to fired and sets their position to the one passed in
	Arguments : A vec2 position.
	Precondition : None.
	Postcondition : A laser is set to fired and sets their position to the one passed in
	Protection : Public.*/
	void Update(float timer);
	/*Prototype:void Update(float timer);
	Description: Updates the laser's position so it moves upward
	Arguments : A timer.
	Precondition : A laser's position is static and unchanging.
	Postcondition : The laser's position is constantly updated.
	Protection : Public.*/
};