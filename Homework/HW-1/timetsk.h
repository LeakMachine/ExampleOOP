#pragma once
#include <iostream>
#include <string>

class Time {
private:
	int hou, min, sec;
public:
	Time();
	Time(int _hou, int _min, int _sec);
	Time(const Time &t);
	Time(std::string str_time);
	~Time();

	void timePrint();
	void timeOperation(const Time &t);
	void timeOperation(int sec_, char op);
	void timeOperation(int hou_, int min_, int sec_);
};