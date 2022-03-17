#include <iostream>
#include <cmath>
#include "class.h"


/* �������: �������� ����������� ������, �������� �������, ������,
�������� ����� ������� ����������� ����������.

����: main() ������ ����� ������ �������� �����������, ����� ���� �������, ��� ���������� �� ���� ��������� (��� ������������),
�� ��� ���� ��������� �� �� ����� ������.

! � main() ������� ���� ��������� ��������� ��������� ���������. ������ �������� �������� �� �������, ������������� �
�������� ��� � �������������� �������. ��������� ������ �������� ��������.

�� ������� ������ ��������� 4 �������:
0. ������� ������
1. ������� �������
2. ������� ������ � �������� �������� ���
3. ������� ����� ������� �����������

�� ���� �� ��������� ������� ����� ������� ������.

���������:
0. ��������� ������, ������� ��������������� � ���������:
- ����� ���� (���������� �������, ����������� � ���� �������������� � �������������),
- ����� ����� (��� �������� ���������)
- ����� ����������� (� ������������� ������ ������������ ��� ������� ������� ������������).

1. �������:
- ��������� ������� ���� (�������� ���� 1 ������, �������� ���� 2 ������ � �.�.),
- ������� ����� � �������� ������������ ������,
- ������� ��������� �������� ��� �������������: �������� �� �������������, ������� ������� � �.�.

��������. �� ����� �������� ������� ��������������, ��� ������ ������ �������� �� � ������ �������, � ����� ��.
�� ������ ���� ������ � ����������� � ���� �����. ������� ����� ������ - ������� ����, � �������� ������� (�����, ��������) -
������� ���������������� ������.

������ ���������� ����������:
����� 3 ������:
1) ����� ����� �������� (����� ������ ����) - inputSides
2) ����� ����� ����������� (����� ������ �����������) -inputTriangle

����� ������������ ������������ - enum Type {bySides, byBaseAndHeight, byPointsCoords};

Triange tr1;
tr1.inputTriangle(bySides);

void inputTriangle(Type _type) {
  switch (_type) {
   case bySides:
     int side1, side2, side3;
     inputSides(&side1, &side2, &side3);   // ��� ����� ���� ��������
     Triange temp(side1, side2, side3);    // ��� �������� ����������� � ���������� ������
     this = temp;
     break;
   // ...
  }
}

���

void inputTriangle(Type _type) {
  switch (_type) {
   case bySides:
     int side1, side2, side3;
     inputSides(&side1, &side2, &side3);   // ��� ����� ���� ��������
     this->side1 = side1;                  // ��� ���������� ��� ������������ �����������, ���������� ���������� ������
     this->side2 = side2;
     this->side3 = side3;
     break;
   // ...
  }
}

*/

enum Type { bySides, byBaseAndHeight, byPointsCoords };

int main() {
    int user_choosen;
    int AB, BC, AC;
    int A[2], B[2], C[2];
    int h;
    float p, S;
    bool exit_flag = false, back_flag;

    Type _inputType;

    while (!exit_flag) {
        back_flag = false;
        std::cout << "Ways to define a triangle:" << std::endl
            << "1) by three sides," << std::endl
            << "2) by base and height," << std::endl
            << "3) by three points" << std::endl
            << "Input: ";
        std::cin >> user_choosen;

        switch (user_choosen) {
        case 1:
            _inputType = bySides;
            while (1) {
                std::cout << "Input 3 side of triangle (between space): ";
                std::cin >> AB >> BC >> AC;
                if (!(AB + BC > AC && AB + AC > BC && AC + BC > AB)) {
                    std::cout << "Input error: triangle dont exist" << std::endl;
                    std::cout << "Try again" << std::endl;
                    continue;
                }
                break;
            }
            break;
        case 2:
            _inputType = byBaseAndHeight;
            std::cout << "Input base of triangle: ";
            std::cin >> AB;
            std::cout << "Input height of triangle: ";
            std::cin >> h;
            break;
        case 3:
            _inputType = byPointsCoords;
            std::cout << "Input 1st point's coordinates (between space): ";
            std::cin >> A[0] >> A[1];
            std::cout << "Input 2nd point's coordinates (between space): ";
            std::cin >> B[0] >> B[1];
            std::cout << "Input 3rd point's coordinates (between space): ";
            std::cin >> C[0] >> C[1];
            break;
        default:
            std::cout << "Input error: error in input" << std::endl;
        }

        while (!back_flag) {
            std::cout << "Methods: 1) get square," << std::endl
                << "2) get perimeter, " << std::endl
                << "3) get type of triangle," << std::endl
                << "4) compare with another triangle by square," << std::endl
                << "5) back to first menu," << std::endl
                << "0) exit," << std::endl
                << "Input: ";
            std::cin >> user_choosen;

            switch (user_choosen) {
            case 0:
                exit_flag = true;
                break;
            case 1:
                if (_inputType == bySides) {
                    if (AB + BC > AC && AB + AC > BC && AC + BC > AB) {
                        p = (AB + BC + AC) * 0.5;
                        S = sqrt(p * (p - AB) * (p - BC) * (p - AC));
                        std::cout << "Square of triangle: S = " << S << std::endl;
                    }
                    else {
                        std::cout << "Input error: triangle dont exist" << std::endl;
                    }
                }
                else if (_inputType == byBaseAndHeight) {
                    if (AB > AC && AB > BC && h != 0)
                        S = 0.5 * AB * h;
                    else if (AC > AB && AC > BC && h != 0)
                        S = 0.5 * AC * h;
                    else if (BC > AC && BC > AB && h != 0)
                        S = 0.5 * BC * h;
                    else {
                        std::cout << "Input error: triangle dont exist" << std::endl;
                    }
                }
                else if (_inputType == byPointsCoords) {
                    S = 0.5 * abs(((A[0] - C[0]) * (B[1] - C[1])) - ((B[0] - C[0]) * (A[1] - C[1])));
                }
                system("pause");
                system("cls");
                break;
            case 2:
                if (_inputType == bySides) {
                    p = AB + BC + BC;
                }
                else if (_inputType == byBaseAndHeight) {
                    std::cout << "Input error: we couldn't find perimeter by your parameters" << std::endl;
                }
                else if (_inputType == byPointsCoords) {
                    int ABx = B[0] - A[0];
                    int ABy = B[1] - A[1];
                    int ACx = C[0] - A[0];
                    int ACy = C[1] - A[1];
                    int BCx = C[0] - B[0];
                    int BCy = C[1] - B[1];
                    p = sqrt(pow(ABx, 2) + pow(ABy, 2)) + sqrt(pow(ACx, 2) + pow(ACy, 2)) + sqrt(pow(BCx, 2) + pow(BCy, 2));
                }
                break;
            case 3:
                if (AB == AC == BC)
                    std::cout << "Triangle is equilateral" << std::endl;
                else if (AB == AC || AC == BC || AB == BC)
                    std::cout << "Triangle is isosceles" << std::endl;
                else if (pow(AB, 2) + pow(AC, 2) == pow(BC, 2) || pow(BC, 2) + pow(AC, 2) == pow(AB, 2) || pow(AB, 2) + pow(BC, 2) == pow(AC, 2))
                    std::cout << "Triangle is isosceles" << std::endl;
                else
                    std::cout << "Triangle is scalene" << std::endl;
                break;
            case 4:
                int S1, S2;
                if (S1 == S2)
                    std::cout << "Triangles have equal square" << std::endl;
                else 
                    std::cout << "Triangles' squares are not equal" << std::endl;
                break;
            case 5:
                back_flag = true;
                break;
            default:
                std::cout << "Input error: error in input" << std::endl;
            }

            if (back_flag || exit_flag) {
                system("cls");
                std::cout << "Last parameters: ";
                if (_inputType == bySides) {
                    std::cout << AB << "x" << BC << "x" << AC << std::endl;
                }
                else if (_inputType == byBaseAndHeight) {
                    std::cout << "a = " << AB << ", h = " << h << std::endl;
                }
                else if (_inputType == byPointsCoords) {
                    std::cout << "(" << A[0] << ", " << A[1] << ")" << ", ";
                    std::cout << "(" << B[0] << ", " << B[1] << ")" << ", ";
                    std::cout << "(" << C[0] << ", " << C[1] << ")" << std::endl;
                }
            }
            break;
        }
    }
    system("cls");
    std::cout << "Goodbay!" << std::endl;
}