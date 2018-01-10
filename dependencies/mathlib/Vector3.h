#pragma once
#include <iostream>
class Vector3
{
public:
	float mX;
	float mY;
	float mZ;
	Vector3();
	Vector3(float x, float y,float z);
	Vector3 operator+(Vector3 &other);
	Vector3 operator-(Vector3 &other);
	Vector3 operator*(float other);
	bool operator==(Vector3 &other);
	float Dot(Vector3 &other);
	Vector3 Cross(Vector3 &other);
	Vector3 Normalize();
	float Magnitude();
	friend std::istream& operator >> (std::istream & input, Vector3 &q);
	friend std::ostream & operator<<(std::ostream & output, const Vector3 &q);
};
