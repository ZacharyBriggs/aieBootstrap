#pragma once
#include <iostream>
class Matrix2
{
public:
	float mMat[4];
	Matrix2();
	Matrix2(float mat[4]);
	Matrix2(float indexA,float indexB,float indexC,float indexD);
	Matrix2 operator+(Matrix2 &other);
	Matrix2 operator-(Matrix2 &other);
	Matrix2 operator*(Matrix2 &other);
	Matrix2 operator*(int &other);
	Matrix2 RotateX(float angle);
	Matrix2 RotateY(float angle);
	friend std::istream& operator >> (std::istream &input, Matrix2 &other);
	friend std::ostream& operator << (std::ostream &output, Matrix2 &other);
};
