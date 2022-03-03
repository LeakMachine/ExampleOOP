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

Time Time::operator+(int _sec) {
	Time timeTemp;
	int totSecBfr = ((this->hou * 60 + this->min) * 60 + this->sec);
	int totSecAfr = totSecBfr + _sec;
	timeTemp.hou = (totSecAfr / 3600);
	timeTemp.min = ((totSecAfr / 60) - (timeTemp.hou * 60));
	timeTemp.sec = (totSecAfr - ((timeTemp.min * 60) + (timeTemp.hou * 3600)));
	if (timeTemp.hou == 24)
		timeTemp.hou = 0;
	if (timeTemp.min == 60)
		timeTemp.min = 0;
	if (timeTemp.sec == 60)
		timeTemp.sec = 0;

	return timeTemp;
};

Time Time::operator-(int _sec) {
	Time timeTemp;
	int totSecBfr = ((this->hou * 60 + this->min) * 60 + this->sec);
	int totSecAfr = totSecBfr - _sec;
	timeTemp.hou = (totSecAfr / 3600);
	timeTemp.min = ((totSecAfr / 60) - (timeTemp.hou * 60));
	timeTemp.sec = (totSecAfr - ((timeTemp.min * 60) + (timeTemp.hou * 3600)));
	if (timeTemp.hou == 24)
		timeTemp.hou = 0;
	if (timeTemp.min == 60)
		timeTemp.min = 0;
	if (timeTemp.sec == 60)
		timeTemp.sec = 0;

	return timeTemp;
};

std::ostream& operator<< (std::ostream& out, const Time& t) {
	std::string hous = std::to_string(t.hou);
	std::string mins = std::to_string(t.min);
	std::string secs = std::to_string(t.sec);
	if (t.hou < 10 && t.hou > -10) {
		hous = "0" + hous;
	}
	if (t.min < 10 && t.min > -10) {
		mins = "0" + mins;
	}
	if (t.sec < 10 && t.sec > -10) {
		secs = "0" + secs;
	}
	out << "Current time is: " << hous << ":" << mins << ":" << secs;
	return out;
};

std::istream& operator>> (std::istream& in, Time& t) {
	in >> t.hou;
	in >> t.min;
	in >> t.sec;

	return in;
};

Time& Time::operator=(const Time& t) {
	this->hou = t.hou;
	this->min = t.min;
	this->sec = t.sec;

	return *this;
};

bool Time::operator==(const Time& t) {
	int totSec1 = ((this->hou * 60 + this->min) * 60 + this->sec);
	int totSec2 = ((t.hou * 60 + t.min) * 60 + t.sec);
	return (totSec1 == totSec2);
};

bool operator!=(const Time& t1, const Time& t2) {
	return !(&t1 == &t2);
};