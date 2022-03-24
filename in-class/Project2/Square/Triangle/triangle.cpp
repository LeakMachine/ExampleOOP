#include "triangle.h"

CPoint::CPoint()
{
	x = 0;
	y = 0;
}

CPoint::CPoint(int _x, int _y)
{
	x = _x;
	y = _y;
}

CTriangle::CTriangle(CPoint _A, CPoint _B, CPoint _C)
{
	A.x = _A.x;
	A.y = _A.y;
	B.x = _B.x;
	B.y = _B.y;
	C.x = _C.x;
	C.y = _C.y;
}

float CTriangle::calculateAB()
{
	return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}

float CTriangle::calculateAC()
{
	return sqrt(pow(A.x - C.x, 2) + pow(A.y - C.y, 2));
}

float CTriangle::calculateBC()
{
	return sqrt(pow(B.x - C.x, 2) + pow(B.y - C.y, 2));
}

float* CTriangle::calculateSides()
{
	float* sides = new float[3];
	sides[0] = calculateAB();
	sides[1] = calculateAC();
	sides[2] = calculateBC();
	return sides;
}

float CTriangle::calculateS()
{
	float* sides = new float[3];
	sides = calculateSides();
	float p = (sides[0] + sides[1] + sides[2]) * 0.5;
	return sqrt(p * (p - sides[0]) * (p - sides[1]) * (p - sides[2]));
}

float CTriangle::calculateP()
{
	float* sides = new float[3];
	sides = calculateSides();
	return sides[0] + sides[1] + sides[2];
}
