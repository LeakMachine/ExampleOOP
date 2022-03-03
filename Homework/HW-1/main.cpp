#include "timetsk.h"
#include <iostream>

using namespace std;

int main() {
	std::string timeString1, timeString2;
	
	cout << "enter time string" << endl;
	cin >> timeString1;

	Time time_0, time_1, time_6;
	Time time_2(12, 23, 34);
	Time time_3(time_2);
	Time time_4(timeString1);
	Time time_5;
	
	cout << time_0 << endl;

	cout << "enter time, hour - minute - second" << endl;
	cin >> time_1;

	time_5 = time_2;

	cout << "add and substract" << endl;
	time_2 = time_2 + 26;
	cout << time_2 << endl;
	time_5 = time_5 - 35;
	cout << time_5 << endl;

	cout << time_4 << endl;

	cout << "time to string" << endl;
	timeString2 = time_2.timeToString(timeString2);
	cout << timeString2 << endl;

	cout << time_3 << endl;

	if (time_2 != time_0)
		cout << "test 1" << endl;
	if (time_0 == time_6)
		cout << "test 2" << endl;


	system("pause");
	return 0;
}