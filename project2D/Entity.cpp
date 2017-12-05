#include "Entity.h"
Entity::Entity()
{
	mX = 640;
	mY = 360;
}
Entity::Entity(int x, int y)
{
	mX = x;
	mY = y;
}
Entity::~Entity()
{
}