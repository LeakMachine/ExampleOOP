#pragma once
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <string>

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

class Train {
public:
	int id;

	std::string route[10];
};

class Lastochka : public Train {
public:
	LasWagon wagons[8];
public:
	void test_func();

};

class Branded : public Train {
public:
	ResWagon rWagonsBr[4];
	CoupeWagon cWagonsBr[6];
	SVWagon svWagonsBr[2];

public:

};

class Swift : public Train {
public:
	ResWagon rWagonsSw[8];
	CoupeWagon cWagonsSw[4];
public:

};


class GorkyRailway : public Swift, public Branded, public Lastochka {
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
	void orderAccept(Date _date, int _trainID,int _wagonID, int _wagonType, FullName _name, int _counter, std::string _stationDeparture, std::string _stationArrival);
	bool orderCheckAvailability(int _counter, int _wagonType);
	//bool orderCheckSeatAvailability(int _counter);
	void orderReserveSeats(int _counter,int _wagonID, int _seatID);
	int orderCountPrice(int _counter);
	void orderCancel(int _counter);
	std::string orderFormCheque(int _counter, int _counter2);

	int getTrainID(int _traintype, int _counter);
	std::string getStation(int _traintype, int _counter, int _stationtype);

	void print();
	void print2(int _counter);
};
