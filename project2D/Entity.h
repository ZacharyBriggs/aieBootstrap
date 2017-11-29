#pragma once
#include <Vector2.h>
class Entity
{
public:
	Vector2 mPos;
	Vector2 mScale;
	Entity();
	/*Prototype:Entity();
	Description: Constructor for Entity class
	Arguments : None.
	Precondition : None.
	Postcondition : A member of the Entity class is created.
	Protection : Public.*/
	~Entity();
	/*Prototype:~Entity();
	Description: Destructor for Entity class
	Arguments : None.
	Precondition : None.
	Postcondition : An Entity is deleted.
	Protection : Public.*/
};