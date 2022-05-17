#pragma once
#include <time.h>
#include <stdlib.h>
#include <iostream>

struct Date {
	int day, month, year;
};

struct Seat {
	int id;
	bool available;
};

struct LasWagon {
	int id;
	Seat regularSeats[100];
};

struct SVWagon {
	int id;
	Seat regularSeats[18];
};

struct ResWagon {
	int id;
	Seat upperSeats[27], lowerSeats[27];
};

struct CoupeWagon {
	int id;
	Seat upperSeats[18], lowerSeats[18];
};

struct Lastochka {
	int id;
	LasWagon wagons[8];
};

struct Branded {
	int id;
	ResWagon rWagons[4];
	CoupeWagon cWagons[6];
	SVWagon svWagons[2];
};

struct Swift {
	int id;
	ResWagon rWagons[8];
	CoupeWagon cWagons[4];
};


class GorkyRailway {
protected:
	Lastochka lTrain[3];
	Branded bTrain;
	Swift sTrain;
public:
	GorkyRailway();

	void printshit();
};

class RailTicketOffice : GorkyRailway {
private:
	GorkyRailway gr;
	Date date;

public:

};
