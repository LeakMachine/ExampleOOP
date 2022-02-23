#include "timetsk.h"

Time::Time() {
	hou = 0;
	min = 0;
	sec = 0;
}

Time::Time(int _hou, int _min, int _sec) {
	hou = _hou;
	min = _min;
	sec = _sec;
}

Time::Time(const Time& t) {
	hou = t.hou;
	min = t.min;
	sec = t.sec;
}

Time::Time(std::string str_time) {
	hou = stoi(str_time.substr(0, 2));
	min = stoi(str_time.substr(3, 2));
	sec = stoi(str_time.substr(6, 2));
}

Time::~Time() {
	hou = 0;
	min = 0;
	sec = 0;
}

void Time::timePrint() {
	std::string hous = std::to_string(hou);
	std::string mins = std::to_string(min);
	std::string secs = std::to_string(sec);
	if (hou < 10 && hou > -10) {
		hous = "0" + hous;
	}
	if (min < 10 && min > -10 ) {
		mins = "0" + mins;
	}
	if (sec < 10 && sec > -10) {
		secs = "0" + secs;
	}

	std::string stime = hous + ":" + mins + ":" + secs;

	std::cout << "Current time is: " << stime << std::endl;	
}

void Time::timeOperation(const Time& t) {
	if (hou == t.hou && min == t.min && sec == t.sec)
		std::cout << "Times are equal" << std::endl;
	else 
		std::cout << "Times are not equal" << std::endl;
}	

void Time::timeOperation(int sec_, char op) {
	switch (op) {
		case '+': {
			sec = sec + sec_;
			if (sec >= 60) {
				while (sec >= 60) {
					sec = sec - 60;
					min++;
				}
			}
			if (min >= 60) {
				while (min >= 60) {
					min = min - 60;
					hou++;
				}
			}
			if (hou >= 24) {
				while (hou >= 24) {
					hou = hou - 24;
				}
			}
			break;
		}
		case '-': {
			sec = sec - sec_;
			if (sec <= 0) {
				while (sec <= 0) {
					sec = sec + 60;
					min--;
				}
				if (sec == 60) {
					sec = sec - 60;
					min++;
				}
			}
			if (min <= 0) {
				while (min <= 0) {
					min = min + 60;
					hou--;
				}
				if (min == 60) {
					min = min - 60;
					hou++;
				}
			}
			if (hou <= 0) {
				while (hou <= 0) {
					hou = hou + 24;
				}
				if (hou == 24) {
					hou = 0;
				}
			}
			break;
		}
		default: {
			std::cout << "Invalid operation." << std::endl;
			break;
		}
	}
}

void Time::timeOperation( int hou_, int min_, int sec_) {
	hou = hou_;
	min = min_;
	sec = sec_;
}