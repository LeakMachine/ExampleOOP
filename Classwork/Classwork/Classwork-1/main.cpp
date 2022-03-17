#include <iostream>
#include <cmath>
#include "class.h"


/* Задание: дописать пропущенные методы, выделить функции, классы,
заменить часть функций перегрузкой операторов.

ЦЕЛЬ: main() должен стать хорошо читаемой структрутой, чтобы было понятно, что происходит во всей программе (без комментариев),
но при этом помещался бы на одном экране.

! В main() вносить свои изменения структуры программы запрещено. Только заменять действия на аналоги, реализованные в
функциях или с использованием классов. СТРУКТУРА ДОЛЖНА ОСТАТЬСЯ ИСХОДНОЙ.

На гитхабе должно появиться 4 коммита:
0. дописал методы
1. выделил функции
2. выделил классы и применил принципы ООП
3. заменил часть функций операторами

То есть по окончании каждого этапа делайте коммит.

Подсказки:
0. Возможные классы, которые проглядыываются в программе:
- класс МЕНЮ (объединяет функции, относящиеся к меню взаимодействия с пользователем),
- класс ТОЧКА (для хранения координат)
- класс ТРЕУГОЛЬНИК (в конструкторах должны отображаться все способы задания треугольника).

1. Функции:
- различные функции меню (показать меню 1 уровня, показать меню 2 уровня и т.д.),
- функции ввода и проверки корректности данных,
- функции различных действий над треугольником: проверка на существование, подсчёт площади и т.д.

Указание. На этапе создания классов предполагается, что объект класса создаётся не в данной функции, а после неё.
Не лепите ввод данных и конструктор в один метод. Функции ввода данных - функции МЕНЮ, а создание объекта (точки, например) -
функции соответствующего класса.

Пример допустимой реализации:
Через 3 метода:
1) метод ввода значений (метод класса меню) - inputSides
2) метод ввода треугльника (метод класса треугольник) -inputTriangle

Далее используется перечисление - enum Type {bySides, byBaseAndHeight, byPointsCoords};

Triange tr1;
tr1.inputTriangle(bySides);

void inputTriangle(Type _type) {
  switch (_type) {
   case bySides:
     int side1, side2, side3;
     inputSides(&side1, &side2, &side3);   // тут сидит ввод значений
     Triange temp(side1, side2, side3);    // тут создаётся треугольник с указанными полями
     this = temp;
     break;
   // ...
  }
}

или

void inputTriangle(Type _type) {
  switch (_type) {
   case bySides:
     int side1, side2, side3;
     inputSides(&side1, &side2, &side3);   // тут сидит ввод значений
     this->side1 = side1;                  // тут изменяется уже существующий треугольник, заполнение указанными полями
     this->side2 = side2;
     this->side3 = side3;
     break;
   // ...
  }
}

*/


void userPick1(int* chosen) {
    std::cout << "Ways to define a triangle:" << std::endl
        << "1) by three sides," << std::endl
        << "2) by base and height," << std::endl
        << "3) by three points" << std::endl
        << "Input: ";
    std::cin >> (*chosen);
};

void userPick2(int* chosen) {
    std::cout << "Methods: 1) get square," << std::endl
        << "2) get perimeter, " << std::endl
        << "3) get type of triangle," << std::endl
        << "4) compare with another triangle by square," << std::endl
        << "5) back to first menu," << std::endl
        << "0) exit," << std::endl
        << "Input: ";
    std::cin >> (*chosen);
};

void inputBaseH(int* base, int* height) {
    int AB = (*base), h = (*height);
    std::cout << "Input base of triangle: ";
    std::cin >> AB;
    std::cout << "Input height of triangle: ";
    std::cin >> h;
    (*base) = AB; (*height) = h;
};

void inputSides(int* side1, int* side2, int* side3) {
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

void inputCoordinates(int coord1[], int coord2[], int coord3[]) {
    std::cout << "Input 1st point's coordinates (between space): ";
    std::cin >> coord1[0] >> coord1[1];
    std::cout << "Input 2nd point's coordinates (between space): ";
    std::cin >> coord2[0] >> coord2[1];
    std::cout << "Input 3rd point's coordinates (between space): ";
    std::cin >> coord3[0] >> coord3[1];
};

void calcSqSides(int side1, int side2, int side3) {
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

void calcSqBaseH(int side1, int height) {
    int AB = side1; int h = height; float S;
    if (h != 0) {
        S = 0.5 * AB * h;
        std::cout << "Square of triangle: S = " << S << std::endl;
    }
    else {
        std::cout << "Input error: triangle dont exist" << std::endl;
    }
};

void calcSqPoints(int coord1[], int coord2[], int coord3[]) {
    float S;
    S = 0.5 * abs(((coord1[0] - coord3[0]) * (coord2[1] - coord3[1])) - ((coord2[0] - coord3[0]) * (coord1[1] - coord3[1])));
    std::cout << "Square of triangle: S = " << S << std::endl;
};

void calcPrSides(int side1, int side2, int side3) {
    int AB = side1; int AC = side2; int BC = side3; float p;
    p = AB + BC + BC;
    std::cout << "Perimeter: " << p << std::endl;
}

void calcPrBaseH() {
    std::cout << "Input error: we couldn't find perimeter by your parameters" << std::endl;
};

void calcPrPoints(int coord1[], int coord2[], int coord3[]) {
    float p;
    int ABx = coord2[0] - coord1[0];
    int ABy = coord2[1] - coord1[1];
    int ACx = coord3[0] - coord1[0];
    int ACy = coord3[1] - coord1[1];
    int BCx = coord3[0] - coord2[0];
    int BCy = coord3[1] - coord2[1];
    p = sqrt(pow(ABx, 2) + pow(ABy, 2)) + sqrt(pow(ACx, 2) + pow(ACy, 2)) + sqrt(pow(BCx, 2) + pow(BCy, 2));
    std::cout << "Perimeter: " << p << std::endl;
};

void triangleType(int side1, int side2, int side3) {
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

void triangleCompare(float S1, float S2) {
    if (S1 == S2)
        std::cout << "Triangles have equal square" << std::endl;
    else
        std::cout << "Triangles' squares are not equal" << std::endl;
};

enum Type { bySides, byBaseAndHeight, byPointsCoords };

void inputTriangle(Type _type) {
    switch (_type) {
    case bySides:
        break;
    case byBaseAndHeight:
        break;
    case byPointsCoords:
        break;
    }
};

void menuExitOrBack(int side1, int side2, int side3, int coord1[], int coord2[], int coord3[], int height, Type input) {
    system("cls");
    int AB = side1; int AC = side2; int BC = side3; int h = height;
    std::cout << "Last parameters: ";
    if (input == bySides) {
        std::cout << AB << "x" << BC << "x" << AC << std::endl;
    }
    else if (input == byBaseAndHeight) {
        std::cout << "a = " << AB << ", h = " << h << std::endl;
    }
    else if (input == byPointsCoords) {
        std::cout << "(" << coord1[0] << ", " << coord1[1] << ")" << ", ";
        std::cout << "(" << coord2[0] << ", " << coord2[1] << ")" << ", ";
        std::cout << "(" << coord3[0] << ", " << coord3[1] << ")" << std::endl;
    }
};


int main() {
    int S1 = 0, S2 = 0;
    int user_choosen;
    int AB, BC, AC;
    int A[2], B[2], C[2];
    int h = 0;
    float p, S;
    bool exit_flag = false, back_flag;

    Type _inputType;

    while (!exit_flag) {
        back_flag = false;
        userPick1(&user_choosen);
        switch (user_choosen) {
        case 1:
            _inputType = bySides;
            inputSides(&AB, &AC, &BC);
            break;
        case 2:
            _inputType = byBaseAndHeight;
            inputBaseH(&AB, &h);
            break;
        case 3:
            _inputType = byPointsCoords;
            inputCoordinates(A, B, C);
            break;
        default:
            std::cout << "Input error: error in input" << std::endl;
        }

        while (!back_flag) {
            userPick2(&user_choosen);
            switch (user_choosen) {
            case 0:
                exit_flag = true;
                break;
            case 1:
                if (_inputType == bySides) {
                    calcSqSides(AB, AC, BC);
                }
                else if (_inputType == byBaseAndHeight) {
                    calcSqBaseH(AB, h);
                }
                else if (_inputType == byPointsCoords) {
                    calcSqPoints(A, B, C);
                }
                system("pause");
                system("cls");
                break;
            case 2:
                if (_inputType == bySides) {
                    calcPrSides(AB, AC, BC);
                }
                else if (_inputType == byBaseAndHeight) {
                    calcPrBaseH();
                }
                else if (_inputType == byPointsCoords) {
                    calcPrPoints(A, B, C);
                }
                break;
            case 3:
                triangleType(AB, AC, BC);
                break;
            case 4:
                triangleCompare(S1, S2);
                break;
            case 5:
                back_flag = true;
                break;
            default:
                std::cout << "Input error: error in input" << std::endl;
            }

            if (back_flag || exit_flag) {
                menuExitOrBack(AB, AC, BC, A, B, C, h, _inputType);
            }
            break;
        }
    }
    system("cls");
    std::cout << "Goodbay!" << std::endl;
}
