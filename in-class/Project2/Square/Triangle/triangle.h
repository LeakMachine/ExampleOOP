#pragma once
#include <cmath>

class CPoint {
	int x;
	int y;
public:
	CPoint();
	CPoint(int _x, int _y);

	friend class CTriangle;
};

class CTriangle {
	CPoint A;
	CPoint B;
	CPoint C;
public:
	CTriangle(CPoint _A, CPoint _B, CPoint _C);

	float calculateAB();
	float calculateAC();
	float calculateBC();

	float* calculateSides();

	float calculateS();
	float calculateP();
};

