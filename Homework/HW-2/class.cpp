#include "class.h"

Hex::Hex() {
	size = 5;
	hex = new unsigned char[size];
}

Hex::Hex(int _size) {
	size = _size;
	hex = new unsigned char[size];
}

//Hex::~Hex() {
//	if (size) {
//		delete[] hex;
//	}
//	size = 0;
//};

std::ostream& operator<< (std::ostream& out, const Hex& h) {
	std::ofstream ofile{ "output.txt" };
	for (int i = 0; i < h.size; i++)
		ofile << h.hex[i];
	return out;
};

std::istream& operator>> (std::istream& in, Hex& h) {
	in >> std::hex >> h.hex;
	return in;
};

bool Hex::operator==(const Hex& h) {
	if (this->size != h.size)
		return false;
	for (int i = 0; i < h.size; i++) {
		if (this->hex[i] != h.hex[i])
			return false;
	}
	return true;
};

bool Hex::operator!=(const Hex& h) {
	if (this->size != h.size)
		return true;
	for (int i = 0; i < h.size; i++) {
		if (this->hex[i] != h.hex[i])
			return true;
	}
	return false;
};

Hex& Hex::operator=(const Hex& h) {
	for (int i = 0; i < size; i++) {
		this->hex[i] = h.hex[i];
	}

	return *this;
};

unsigned char& Hex::operator[](int _index) {
	if (_index > size) {
		return hex[size - 1];
	}
	return hex[_index];
};

unsigned int hexToInt(int _size, unsigned char* _array) {
	std::string hexStr;
	char ch;
	std::string hexToIntS;
	for (int i = _size - 1; i >= 0; i--) {
		ch = _array[i];
		hexStr = ch + hexStr;
	}
	unsigned int n;
	std::istringstream(hexStr) >> std::hex >> n;
	std::stringstream test;
	test << std::dec << n << std::endl;
	unsigned int k;
	test >> k;

	unsigned int hexToIntI = k;
	return hexToIntI;
};

Hex Hex::operator-(const Hex& h) {
	unsigned int hex1int = hexToInt(this->size, this->hex);
	unsigned int hex2int = hexToInt(h.size, h.hex);
	unsigned int hexRes = hex1int - hex2int;

	std::string string1 = std::to_string(hexRes);

	unsigned int n;
	std::istringstream(string1) >> std::dec >> n;
	std::stringstream test;
	test << std::hex << n << std::endl;
	std::string k;
	test >> k;
	std::cout << k << std::endl;

	Hex tempHex;

	for (int i = 0; i < h.size; i++) {
		char temp = string1[i];
		tempHex.hex[i] = (unsigned char)(temp);
	}

	return tempHex;
};


Hex Hex::operator+(const Hex& h) {
	unsigned int hex1int = hexToInt(this->size, this->hex);
	unsigned int hex2int = hexToInt(h.size, h.hex);
	unsigned int hexRes = hex1int + hex2int;

	std::string string1 = std::to_string(hexRes);

	unsigned int n;
	std::istringstream(string1) >> std::dec >> n;
	std::stringstream test;
	test << std::hex << n << std::endl;
	std::string k;
	test >> k;
	std::cout << k << std::endl;

	Hex tempHex;

	for (int i = 0; i < h.size; i++) {
		char temp = string1[i];
		tempHex.hex[i] = (unsigned char)(temp);
	}

	return tempHex;
};