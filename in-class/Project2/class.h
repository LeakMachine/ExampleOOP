#pragma once
#include <iostream>
#include <string>

typedef int meters_t;
typedef int miles_t;
typedef int kilometers_t;

struct DistanceType {
	int meters_t;
	int kilometers_t;
	int miles_t;
};

class Distance {
private:
	int distance;

public:

	Distance();
	Distance(meters_t _meters);
	Distance(kilometers_t _kilometers);
	Distance(miles_t _miles);

	Distance operator+(const Distance& d);
	Distance operator-(const Distance& d);
	Distance operator*(const Distance& d);
	Distance& operator=(const Distance& d);
	bool operator==(const Distance& d);
	bool operator!=(const Distance& d);
	bool operator>(const Distance& d);
	bool operator<(const Distance& d);
	bool operator>=(const Distance& d);
	bool operator<=(const Distance& d);

	friend std::ostream& operator<< (std::ostream& out, const Distance& d);

	void to_miles(int _meters);
	void to_kilometers(int _kilometers);
	void print_distance();
};