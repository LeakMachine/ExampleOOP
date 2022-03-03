#pragma once
#include <iostream>
#include <string>

class Time {
private:
	int hou, min, sec;
public:
	// все необходимые конструкторы
	Time();
	Time(int _hou, int _min, int _sec);
	Time(const Time &t);
	Time(std::string str_time); // преобразование времени из строки

	

	std::string timeToString(std::string _string); // метод представления времени как строки


	// перегрузки перегрузочки 
	
	Time& operator=(const Time& t);
	bool operator==(const Time& t);
	friend bool operator!=(const Time& t1, const Time& t2);
	Time operator+(int _sec);
	Time operator-(int _sec);
	friend std::ostream& operator<< (std::ostream &out, const Time& t);
	friend std::istream& operator>> (std::istream &in, Time& t);
};
