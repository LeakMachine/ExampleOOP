#pragma once
#include <iostream>
#include <string>

class Time {
private:
	int hou, min, sec;
public:
	// все необходимые конструкторы
	Time();
	Time(int _hou, int _min, int _sec);
	Time(const Time &t);
	Time(std::string str_time); // преобразование времени из строки
	~Time();

	

	std::string timeToString(std::string _string); // метод представления времени как строки


	// перегрузки перегрузочки 
	
	void operator=(const Time& t) {
		this->hou = t.hou;
		this->min = t.min;
		this->sec = t.sec;
	};

	bool operator==(const Time& t) {
		int totSec1 = ((this->hou * 60 + this->min) * 60 + this->sec);
		int totSec2 = ((t.hou * 60 + t.min) * 60 + t.sec);
		return (totSec1 == totSec2);
	};

	bool operator!=(const Time& t) {
		int totSec1 = ((this->hou * 60 + this->min) * 60 + this->sec);
		int totSec2 = ((t.hou * 60 + t.min) * 60 + t.sec);
		return (totSec1 != totSec2);
	};

	void operator+(int _sec) {
		int totSecBfr = ((this->hou * 60 + this->min) * 60 + this->sec);
		int totSecAfr = totSecBfr + _sec;
		this->hou = (totSecAfr / 3600);
		this->min = ((totSecAfr / 60) - (this->hou * 60));
		this->sec = (totSecAfr - ((this->min * 60) + (this->hou * 3600)));
		if (this->hou == 24)
			this->hou = 0;
		if (this->min == 60)
			this->min = 0;
		if (this->sec == 60)
			this->sec = 0;
	};

	void operator-(int _sec) {
		int totSecBfr = ((this->hou * 60 + this->min) * 60 + this->sec);
		int totSecAfr = totSecBfr - _sec;
		this->hou = (totSecAfr / 3600);
		this->min = ((totSecAfr / 60) - (this->hou * 60));
		this->sec = (totSecAfr - ((this->min * 60) + (this->hou * 3600)));
		if (this->hou == 24)
			this->hou = 0;
		if (this->min == 60)
			this->min = 0;
		if (this->sec == 60)
			this->sec = 0;
	};

	friend std::ostream& operator<< (std::ostream &out, const Time& t) {
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

	friend std::istream& operator>> (std::istream &in, Time& t) {
		in >> t.hou;
		in >> t.min;
		in >> t.sec;

		return in;
	};
};