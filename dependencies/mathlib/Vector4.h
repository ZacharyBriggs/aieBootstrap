#pragma once
#include <math.h>
#include <iostream>
class Vector4
{
public:
	float mX;
	float mY;
	float mZ;
	float mW;
	Vector4();
	Vector4(float x, float y, float z, float w);
	Vector4 operator+(Vector4 &other);
	Vector4 operator-(Vector4 &other);
	Vector4 operator*(float other);
	bool operator==(Vector4 &other);
	float Dot(Vector4 &other);
	Vector4 Normalize();
	float Magnitude();
	friend std::istream& operator >> (std::istream & input, Vector4 &q);
	friend std::ostream & operator<<(std::ostream & other, const Vector4 &q);
};