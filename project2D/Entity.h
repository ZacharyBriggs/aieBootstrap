#pragma once
#include <Vector2.h>
class Entity
{
protected:
	Vector2 mPos;
	Vector2 mScale;
public:
	bool mIsAlive;
	Entity();
	~Entity();
	float GetPosX();
	void ChangePosX(float change);
	float GetPosY();
	void ChangePosY(float change);
	int GetWidth();
	int GetHeight();
};
