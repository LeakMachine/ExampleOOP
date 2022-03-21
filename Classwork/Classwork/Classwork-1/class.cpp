#include "class.h"

void Menu::userPick1(int* chosen) {
    std::cout << "Ways to define a triangle:" << std::endl
        << "1) by three sides," << std::endl
        << "2) by base and height," << std::endl
        << "3) by three points" << std::endl
        << "Input: ";
    std::cin >> (*chosen);
};

void Menu::userPick2(int* chosen) {
    std::cout << "Methods: 1) get square," << std::endl
        << "2) get perimeter, " << std::endl
        << "3) get type of triangle," << std::endl
        << "4) compare with another triangle by square," << std::endl
        << "5) back to first menu," << std::endl
        << "0) exit," << std::endl
        << "Input: ";
    std::cin >> (*chosen);
};

void Menu::calcSqSides(int side1, int side2, int side3) {
    int AB = side1; int AC = side2; int BC = side3; float S; float p;
    if (AB + BC > AC && AB + AC > BC && AC + BC > AB) {
        p = (AB + BC + AC) * 0.5;
        S = sqrt(p * (p - AB) * (p - BC) * (p - AC));
        std::cout << "Square of triangle: S = " << S << std::endl;
    }
    else {
        std::cout << "Input error: triangle dont exist" << std::endl;
    }
};

void Menu::calcSqBaseH(int side1, int height) {
    int AB = side1; int h = height; float S;
    if (h != 0) {
        S = 0.5 * AB * h;
        std::cout << "Square of triangle: S = " << S << std::endl;
    }
    else {
        std::cout << "Input error: triangle dont exist" << std::endl;
    }
};

void Menu::calcSqPoints(Point a, Point b, Point c) {
    float S;
    S = 0.5 * abs(((a.getCoordX() - c.getCoordX()) * (b.getCoordY() - c.getCoordY())) - ((b.getCoordX() - c.getCoordY()) * (a.getCoordY() - c.getCoordY())));
    std::cout << "Square of triangle: S = " << S << std::endl;
};

void Menu::calcPrSides(int side1, int side2, int side3) {
    int AB = side1; int AC = side2; int BC = side3; float p;
    p = AB + BC + BC;
    std::cout << "Perimeter: " << p << std::endl;
}

void Menu::calcPrBaseH() {
    std::cout << "Input error: we couldn't find perimeter by your parameters" << std::endl;
};

void Menu::calcPrPoints(Point a, Point b, Point c) {
    float p;
    int ABx = b.getCoordX() - a.getCoordX();
    int ABy = b.getCoordY() - a.getCoordY();
    int ACx = c.getCoordX() - a.getCoordX();
    int ACy = c.getCoordY() - a.getCoordY();
    int BCx = c.getCoordX() - b.getCoordX();
    int BCy = c.getCoordY() - b.getCoordY();
    p = sqrt(pow(ABx, 2) + pow(ABy, 2)) + sqrt(pow(ACx, 2) + pow(ACy, 2)) + sqrt(pow(BCx, 2) + pow(BCy, 2));
    std::cout << "Perimeter: " << p << std::endl;
};

void Menu::inputBaseH(int* base, int* height) {
    int AB = (*base), h = (*height);
    std::cout << "Input base of triangle: ";
    std::cin >> AB;
    std::cout << "Input height of triangle: ";
    std::cin >> h;
    (*base) = AB; (*height) = h;
};

void Menu::inputSides(int* side1, int* side2, int* side3) {
    int AB = (*side1), AC = (*side2), BC = (*side3);
    while (1) {
        std::cout << "Input 3 side of triangle (between space): ";
        std::cin >> AB >> AC >> BC;
        if (!(AB + BC > AC && AB + AC > BC && AC + BC > AB)) {
            std::cout << "Input error: triangle dont exist" << std::endl;
            std::cout << "Try again" << std::endl;
            continue;
        }
        (*side1) = AB; (*side2) = AC; (*side3) = BC;
        break;
    }
};

void Menu::inputCoordinates(Point a, Point b, Point c) {
    int Ax, Ay, Bx, By, Cx, Cy;
    std::cout << "Input 1st point's coordinates (between space): ";
    std::cin >> Ax >> Ay;
    std::cout << "Input 2nd point's coordinates (between space): ";
    std::cin >> Bx >> By;
    std::cout << "Input 3rd point's coordinates (between space): ";
    std::cin >> Cx >> Cy;
    a.setCoordX(Ax);     a.setCoordY(Ay);
    b.setCoordX(Bx);     b.setCoordY(By);
    c.setCoordX(Cx);     c.setCoordY(Cy);
};

Triangle::Triangle()
{
    side1 = 0; side2 = 0; side3 = 0; h = 0;
    A.setCoordX(0);     A.setCoordY(0);
    B.setCoordX(0);     B.setCoordY(0);
    C.setCoordX(0);     C.setCoordY(0);
}

Triangle::Triangle(int _side1, int _side2, int _side3)
{
    side1 = _side1;
    side2 = _side2;
    side3 = _side3;
}

Triangle::Triangle(int _side1, int _h)
{
    side1 = _side1;
    h = _h;
}

Triangle::Triangle(Point a, Point b, Point c) 
{
    A.setCoordX(a.getCoordX());     A.setCoordY(a.getCoordY());
    B.setCoordX(b.getCoordX());     B.setCoordY(b.getCoordY());
    C.setCoordX(c.getCoordX());     C.setCoordY(c.getCoordY());
}

Point::Point()
{
    x = 0;
    y = 0;
}

void Point::setCoordX(int coord)
{
    x = coord;
}

void Point::setCoordY(int coord)
{
    y = coord;
}

int Point::getCoordX()
{
    return x;
}

int Point::getCoordY()
{
    return y;
}

void Triangle::menuExitOrBack(Type _type) {
    system("cls");
    int AB = side1; int AC = side2; int BC = side3;
    std::cout << "Last parameters: ";
    if (_type == bySides) {
        std::cout << AB << "x" << BC << "x" << AC << std::endl;
    }
    else if (_type == byBaseAndHeight) {
        std::cout << "a = " << AB << ", h = " << h << std::endl;
    }
    else if (_type == byPointsCoords) {
        std::cout << "(" << A.getCoordX() << ", " << A.getCoordY() << ")" << ", ";
        std::cout << "(" << B.getCoordX() << ", " << B.getCoordY() << ")" << ", ";
        std::cout << "(" << C.getCoordX() << ", " << C.getCoordY() << ")" << std::endl;
    }
}
bool Triangle::operator==(const Triangle& t)
{
    return false;
}
;

void Triangle::triangleType() {
    int AB = side1; int AC = side2; int BC = side3;
    if (AB == AC == BC) {
        std::cout << "Triangle is equilateral" << std::endl;
    }
    else if (AB == AC || AC == BC || AB == BC && !(AB == AC == BC)) {
        std::cout << "Triangle is isosceles" << std::endl;
    }
    else if (pow(AB, 2) + pow(AC, 2) == pow(BC, 2) || pow(BC, 2) + pow(AC, 2) == pow(AB, 2) || pow(AB, 2) + pow(BC, 2) == pow(AC, 2)) {
        std::cout << "Triangle is isosceles" << std::endl;
    }
    else {
        std::cout << "Triangle is scalene" << std::endl;
    }
};

void Triangle::inputTriangle(Type _type)
{
    Triangle temp;
    switch (_type) {
        Menu menu;
    case bySides:
        menu.inputSides(&side1, &side2, &side3);
        temp.side1 = side1; temp.side2 = side2; temp.side3 = side3;
        *this = temp;
        break;
    case byBaseAndHeight:
        menu.inputBaseH(&side1, &h);
        temp.side1 = side1; temp.h = h;
        *this = temp;
        break;
    case byPointsCoords:
        menu.inputCoordinates(A, B, C);
        temp.A.setCoordX(A.getCoordX()); temp.A.setCoordY(A.getCoordY());
        temp.B.setCoordX(B.getCoordX()); temp.B.setCoordY(B.getCoordY());
        temp.C.setCoordX(C.getCoordX()); temp.C.setCoordY(C.getCoordY());
        *this = temp;
        break;
    }
}

void Triangle::calcTrianglePr(Type _type)
{
    switch (_type) {
        Menu menu;
    case bySides:
        menu.calcPrSides(side1, side2, side3);
        break;
    case byBaseAndHeight:
        menu.calcPrBaseH();
        break;
    case byPointsCoords:
        menu.calcPrPoints(A, B, C);
        break;
    }
}

void Triangle::calcTriangleSq(Type _type)
{
    switch (_type) {
        Menu menu;
    case bySides:
        menu.calcSqSides(side1, side2, side3);
        break;
    case byBaseAndHeight:
        menu.calcSqBaseH(side1, h);
        break;
    case byPointsCoords:
        menu.calcSqPoints(A, B, C);
        break;
    }
    system("pause");
    system("cls");
}