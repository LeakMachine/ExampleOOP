#include "Game.h"

int main() {
  // ����� ������������ �� ���������
  Warrior user_0001;

  //Axe user_0001_weapon;
  Axe user_0002_weapon("Knife", 3.0, 20);
  //Axe user_0003_weapon(user_0002_weapon);

  // ����� ������������ �������������
  Warrior user_0002("Grom", "male", 20.0, 100.0, user_0002_weapon, 30.0);

  // ����� ������������ ������������ �������������
  Warrior user_0004("Grom", "male", 20.0, 100.0, "SUPER AXE", -60.0, 100.0, 30.0);

  // ����� ������������ �����������
  Warrior user_0003(user_0001);

  /// user_0002.health = 10000000; ������!!!!!

  user_0001.print_character_info();
  user_0002.print_character_info();
  user_0003.print_character_info();
  user_0004.print_character_info();

  system("pause");
  return 0;
}