#pragma once
#include <iostream>
#include <cmath>
#include "class.h"

enum Type { bySides, byBaseAndHeight, byPointsCoords };

class Point {
private:
	int x, y;
public:
	Point();

	void setCoordX(int coord);
	void setCoordY(int coord);
    int getCoordX();
    int getCoordY();
};
class Menu {
private:

public:
	void inputBaseH(int* base, int* height);
	void inputSides(int* side1, int* side2, int* side3);
	void inputCoordinates(Point a, Point b, Point c);
	void userPick1(int* chosen);
	void userPick2(int* chosen);
	void calcSqSides(int side1, int side2, int side3);
	void calcSqBaseH(int side1, int height);
	void calcSqPoints(Point a, Point b, Point c);
	void calcPrSides(int side1, int side2, int side3);
	void calcPrBaseH();
	void calcPrPoints(Point a, Point b, Point c);
};
class Triangle {
private:
	Point A, B, C;
	int side1, side2, side3;
	int h;
public:
	Triangle();

	Triangle(int _side1, int _side2, int _side3);
	Triangle(int _side1, int _h);
	Triangle(Point a, Point b, Point c);

	void inputTriangle(Type _type);
	void calcTriangleSq(Type _type);
	void calcTrianglePr(Type _type);
	void triangleType();
	void menuExitOrBack(Type _type);
	
	bool operator==(const Triangle& t);
};