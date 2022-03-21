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


int main() {
    int user_choosen;
    bool exit_flag = false, back_flag;
    Menu menu;
    Type _inputType;

    while (!exit_flag) {
        back_flag = false;
        menu.userPick1(&user_choosen);
        switch (user_choosen) {
        case 1:
            _inputType = bySides;
            break;
        case 2:
            _inputType = byBaseAndHeight;
            break;
        case 3:
            _inputType = byPointsCoords;
            break;
        default:
            std::cout << "Input error: error in input" << std::endl;
        }

        Triangle triangle, triangle2;
        triangle.inputTriangle(_inputType);

        while (!back_flag) {
            menu.userPick2(&user_choosen);
            switch (user_choosen) {
            case 0:
                exit_flag = true;
                break;
            case 1:
                triangle.calcTriangleSq(_inputType);
                break;
            case 2:
                triangle.calcTrianglePr(_inputType);
                break;
            case 3:
                triangle.triangleType();
                break;
            case 4:
                if (triangle == triangle2)
                    std::cout << "epic" << std::endl;
                else
                    std::cout << "unepic" << std::endl;
                break;
            case 5:
                back_flag = true;
                break;
            default:
                std::cout << "Input error: error in input" << std::endl;
            }

            if (back_flag || exit_flag) {
                triangle.menuExitOrBack(_inputType);
            }
            break;
        }
    }
    system("cls");
    std::cout << "Goodbay!" << std::endl;
}