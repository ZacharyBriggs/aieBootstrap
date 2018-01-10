#pragma once
#include <iostream>
class Matrix4
{
public:
	float mMat[16];
	Matrix4();
	Matrix4(float mat[16]);
	Matrix4(float indexA, float indexB, float indexC, float indexD, float indexE, float indexF, float indexG, float indexH, float indexI, float indexJ, float indexK, float indexL, float indexM, float indexN, float indexO, float indexP);
	Matrix4 operator+(Matrix4 &other);
	Matrix4 operator-(Matrix4 &other);
	Matrix4 operator*(Matrix4 &other);
	Matrix4 operator*(int &other);
	Matrix4 RotateX(float angle);
	Matrix4 RotateY(float angle);
	Matrix4 RotateZ(float angle);
	friend std::istream &operator >> (std::istream &input, Matrix4 &other);
	friend std::ostream &operator << (std::ostream &input, Matrix4 &other);
};
