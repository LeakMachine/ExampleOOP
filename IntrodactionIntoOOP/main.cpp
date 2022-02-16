#include "Game.h"

int main() {
  // ����� ������������ �� ���������
  Human user_0001;

  // ����� ������������� �������������
  Gun user_0002_weapon("Vinchester", 3.0, 20);
  Human user_0002("John Wick", "male", 20.0, 100.0, user_0002_weapon, 30.0);

  // ����� ������������ �����������
  Human user_0003(user_0001);

  // ����� ������������ ������������ �������������
  Human user_0004("Lebowski", "male", 10.0, 80.0, "Shotgun", 60.0, 100.0, 0.0);

  // ����� �� �����
  std::cout << "USER 1" << std::endl;
  user_0001.print();

  std::cout << std::endl << "USER 2" << std::endl;
  user_0002.print();

  std::cout << std::endl << "USER 3" << std::endl;
  user_0003.print();

  std::cout << std::endl << "USER 4" << std::endl;
  user_0004.print();

  system("pause");
  return 0;
}