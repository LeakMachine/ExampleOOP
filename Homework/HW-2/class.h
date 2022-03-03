#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

class Hex {
private:
	int size;
	unsigned char *hex;
public:
	//конструкторы
	Hex();
	Hex(int _size);
	Hex(const Hex& h);
	~Hex();

	//перегрузки операторов
	Hex operator+(const Hex& h);
	Hex operator-(const Hex& h);
	friend std::ostream& operator<< (std::ostream& out, const Hex& h);
	friend std::istream& operator>> (std::istream& in, Hex& h);
	bool operator==(const Hex& h);
	bool operator!=(const Hex& h);
	Hex& operator=(const Hex& h);
	unsigned char& operator[](int _index);

};

unsigned int hexToInt(int _size, unsigned char* _array);
