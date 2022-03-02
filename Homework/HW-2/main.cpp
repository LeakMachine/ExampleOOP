#include <iostream>
#include "class.h"

using namespace std;

int main() {

	Hex hex(3), hex2(3), hex3, hex4;

	cin >> hex;
	cin >> hex2;

	hex3 = hex - hex2;
	hex4 = hex + hex2;
	
	cout << hex4;

	return 0;
}