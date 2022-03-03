#include "class.h"
#define KILOMETERCONST 1000;
#define MILECONST 1609;

Distance::Distance() {
	distance = 0;
}

Distance::Distance(meters_t _meters) {
	distance = _meters;
}

Distance::Distance(miles_t _miles) {
	distance = _miles * MILECONST;
}

Distance::Distance(kilometers_t _kilometers) {
	distance = _kilometers * KILOMETERCONST;
}

void Distance::to_miles(int _meters) {
	distance = _meters / MILECONST;
}

void Distance::to_kilometers(int _meters) {
	distance = _meters / KILOMETERCONST;
} 

Distance Distance::operator+(const Distance& d) {
	Distance tempDistance;
	return (tempDistance.distance = this->distance + d.distance);
};

Distance Distance::operator-(const Distance& d) {
	Distance tempDistance;

	return (tempDistance.distance = this->distance - d.distance);
};

Distance Distance::operator*(const Distance& d) {
	Distance tempDistance;

	return (tempDistance.distance = this->distance * d.distance);
};
Distance& Distance::operator=(const Distance& d)
{
	distance = d.distance;
	return *this;
};
bool Distance::operator==(const Distance& d)
{
	if (distance == d.distance)
		return true;
	return false;
};
bool Distance::operator!=(const Distance& d)
{
	if (distance != d.distance)
		return true;
	return false;
};
bool Distance::operator>(const Distance& d)
{
	if (distance > d.distance)
		return true;
	return false;
};
bool Distance::operator<(const Distance& d)
{
	if (distance < d.distance)
		return true;
	return false;
};
bool Distance::operator>=(const Distance& d)
{
	if (distance >= d.distance)
		return true;
	return false;
};
bool Distance::operator<=(const Distance& d)
{
	if (distance <= d.distance)
		return true;
	return false;
};

std::ostream& operator<<(std::ostream& out, const Distance& d)
{
	out << d.distance;
	return out;
};
