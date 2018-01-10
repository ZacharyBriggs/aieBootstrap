#include "Entity.h"
Entity::Entity()
{
}
Entity::~Entity()
{
}
float Entity::GetPosX()
{
	return mPos.mX;
}
void Entity::ChangePosX(float change)
{
	mPos.mX = change;
}
float Entity::GetPosY()
{
	return mPos.mY;
}
void Entity::ChangePosY(float change)
{
	mPos.mY = change;
}
int Entity::GetWidth()
{
	return mScale.mX;
}
int Entity::GetHeight()
{
	return mScale.mY;
}