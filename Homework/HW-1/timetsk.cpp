#include "timetsk.h"

Time::Time() {
	hou = 0;
	min = 0;
	sec = 0;
};

Time::Time(int _hou, int _min, int _sec) {
	hou = _hou;
	min = _min;
	sec = _sec;
};

Time::Time(const Time& t) {
	hou = t.hou;
	min = t.min;
	sec = t.sec;
};

Time::Time(std::string str_time) {
	hou = stoi(str_time.substr(0, 2));
	min = stoi(str_time.substr(3, 2));
	sec = stoi(str_time.substr(6, 2));
};

Time::~Time() {
	hou = 0;
	min = 0;
	sec = 0;
};

std::string Time::timeToString(std::string _string) {
	std::string hous = std::to_string(hou);
	std::string mins = std::to_string(min);
	std::string secs = std::to_string(sec);

	if (hou < 10 && hou > -10) {
		hous = "0" + hous;
	}
	if (min < 10 && min > -10) {
		mins = "0" + mins;
	}
	if (sec < 10 && sec > -10) {
		secs = "0" + secs;
	}

	_string = hous + ":" + mins + ":" + secs;

	return _string;
};
