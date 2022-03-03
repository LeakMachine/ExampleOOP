#include <iostream>
#include "class.h"


using namespace std;

int main() {
	Distance dis1(1000), dis2;

	dis2 = dis1 - 50;

	std::cout << dis2 << std::endl;

	dis2 = dis1 + 50;

	std::cout << dis2 << std::endl;

	dis2 = dis1 * 50;

	std::cout << dis2 << std::endl;

	if (dis1 > dis2) {
		std::cout << "epic win";
	}
	else {
		std::cout << "epic fail";
	}

	return 0;
}