#pragma once
#include <iostream>
class Vector2
{
public:
	float mX;
	float mY;
	Vector2();
	Vector2(float x, float y);
	Vector2 operator+(Vector2 &other);
	Vector2 operator-(Vector2 &other);
	Vector2 operator*(float other);
	bool operator==(Vector2 &other);
	float Dot(Vector2 &other);
	Vector2 Normalize();
	float Magnitude();
	friend std::istream& operator >> (std::istream & input, Vector2 &q);
	friend std::ostream & operator<<(std::ostream & output, const Vector2 &q);
};
