#include <iostream>
#include "class.h"

using namespace std;

int main() {

	Hex hex(3), hex2(3), hex3, hex4;

	cin >> hex;
	cin >> hex2;

	hex3 = hex - hex2;
	hex4 = hex + hex2;

	cout << hex3 << endl;
	cout << hex4 << endl;

	if (hex == hex2)
		cout << "win" << endl;
	else
		cout << "fail" << endl;

	if (hex != hex2)
		cout << "win" << endl;
	else
		cout << "fail" << endl;

	system("pause");
	return 0;
}