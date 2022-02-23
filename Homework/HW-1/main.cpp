#include "timetsk.h"
#include <iostream>

using namespace std;

int main() {
	std::string S;

	std::cout << "Enter time: ";

	std::cin >> S;

	Time time_0;
	Time time_1(S);
	Time time_2(12, 12, 12);
	Time time_3(time_1);
	Time time_4;
	Time time_5;

	time_0.timePrint();
	time_1.timePrint();
	time_2.timePrint();
	time_3.timePrint();
	time_4.timePrint();
	time_5.timePrint();

	time_0.timeOperation(160, '-');
	time_0.timePrint();

	time_5.timeOperation(5,20,30);
	time_5.timePrint();

	time_0.timeOperation(time_4);

	return 0;
}