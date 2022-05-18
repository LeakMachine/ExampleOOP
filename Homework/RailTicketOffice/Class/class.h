#pragma once
#include <time.h>
#include <stdlib.h>
#include <iostream>

struct FullName {
	std::string name, surname, patronymic;
};

struct Date {
	int day, month, year;
};

struct Ticket {
	Date date;
	FullName name;
	int trainID, wagonID, seatID, wagonType;
	std::string stationDeparture, stationArrival;
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
	std::string stationDeparture, stationArrival;
};

struct Branded {
	int id;
	ResWagon rWagons[4];
	CoupeWagon cWagons[6];
	SVWagon svWagons[2];
	std::string stationDeparture, stationArrival;
};

struct Swift {
	int id;
	ResWagon rWagons[8];
	CoupeWagon cWagons[4];
	std::string stationDeparture, stationArrival;
};


class GorkyRailway {
protected:
	Lastochka lTrain[3];
	Branded bTrain;
	Swift sTrain;

public:
	GorkyRailway();

	friend class RailTicketOffice;
};

class RailTicketOffice {
protected:
	GorkyRailway gr;
	Ticket tickets[100];
public:
	void orderAccept(Date _date, int _trainID, int _wagonType, FullName _name, int _counter, std::string _stationDeparture, std::string _stationArrival);
	bool orderCheckAvailability(int _counter, int _wagonType);
	void orderReserveSeats(int _counter,int _wagonID, int _seatID);
	int orderCountPrice(int _counter);
	int orderCancel(int _counter);
	std::string orderFormCheque(int _counter);

	void print();
	void print2(int _counter);
};
