#pragma once

#include <iostream>
#include <string>
#include <time.h>

#define MAX_HEALTH 100
#define CRIT -1

/******************************** WEAPON'S CLASSES **********************************/

class Weapon {
protected:
  std::string name;
  double damage;

public:
  // ������������
  Weapon();
  Weapon(std::string _name, double _damage);
  Weapon(const Weapon &w);

  // ������
  void print();
};

class Gun : public Weapon {
  int cartridges;

public:
  Gun();
  Gun(std::string _name, double _damage, int _cartridges);
  Gun(const Gun &a);

  void print();

  friend class Human;     // ��������� ������ � ������� ���� ���������� ������
};

struct Bow : public Weapon {
  int arrows;
  double extraDamage;
  int time;

public:
  Bow();
  Bow(std::string _name, double _damage, int _arrows, double _extraDamage, int _time);
  Bow(const Bow &a);

  void print();

  friend class Archer;
};

class Axe : public Weapon {
  int strenght;

public:
  Axe();
  Axe(std::string _name, double _damage, int _strenght);
  Axe(const Axe &a);

  void print();

  friend class Warrior;
};

/******************************* CHARACTERS'S CLASSES *******************************/

class Character {
protected:
  std::string name;
  std::string  gender;
  double power;
  double health;

public:
  // ������������
  Character();
  Character(std::string _name, std::string  _gender, double _power);
  Character(const Character& w);

  // ������

  void restoreHealth() { };
  bool crit() const { };
  virtual void attack(Character &ch) = 0;
  virtual bool attacted(double _damage) = 0;
  void print();
};

class Human : public Character {
  Gun weapon;
  int technics;

public:
  Human();
  Human(std::string _name, std::string  _gender, double _power,
    std::string _nameW, double _damage, int _cartridges,
    double _technics);
  Human(std::string _name, std::string  _gender, double _power,
    Gun _weapon, double _technics);
  Human(const Human &w);

  void attack(Character &ch) {
    std::cout << std::endl << name << " ATTACK!" << std::endl;

  };

  bool attacted(double _damage) {
    std::cout << std::endl << name << " WAS ATTACKED!" << std::endl;
    return false;
  };

  void print();
};

class Archer : public Character {
  Bow weapon;
  int dexterity;

public:
  Archer();
  Archer(std::string _name, std::string  _gender, double _power,
    std::string _nameW, double _damage, int _arrows, double _extraDamage,
    int _time, double _dexterity);
  Archer(std::string _name, std::string  _gender, double _power,
    Bow _weapon, double _dexterity);
  Archer(const Archer &w);

  void print();
};

class Warrior : public Character {
  Axe weapon;
  double armor;

public:
  Warrior();
  Warrior(std::string _name, std::string  _gender, double _power,
  std::string _nameW, double _damage, int _strenght,
  double _armor);
  Warrior(std::string _name, std::string  _gender, double _power,
    Axe _weapon, double _armor);
  Warrior(const Warrior &w);

  void print();
};
