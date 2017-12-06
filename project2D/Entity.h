#pragma once
class Entity
{
public:
	int mX;
	int mY;
	int mScaleX;
	int mScaleY;
	float mSpeed;
	Entity();
	Entity(int x, int y);
	~Entity();
};