#include "class.h"
#include <iostream>

GorkyRailway::GorkyRailway()
{
	for (int i = 0; i < 3; i++) {
		lTrain[i].id = rand() % 100 + 1;
		lTrain[i].route[0] = "Station 1";
		lTrain[i].route[1] = "Station 2";
		for (int j = 0; j < 8; j++) {
			lTrain[i].wagons[j].id = j + 1;
			for (int k = 0; k < 100; k++) {
				lTrain[i].wagons[j].regularSeats[k].id = k + 1;
				lTrain[i].wagons[j].regularSeats[k].available = true;
			}
		}
	}
	int wagonCount = 0;
	int seatCount = 0;
	bTrain.id = rand() % 100 + 1;
	bTrain.route[0] = "Station 1";
	bTrain.route[1] = "Station 3";
	for (int j = 0; j < 4; j++) {
		bTrain.rWagonsBr[j].id = j + 1;
		wagonCount++;
		for (int k = 0; k < 27; k++) {
			bTrain.rWagonsBr[j].upperSeats[k].id = k + 1;
			seatCount++;
			bTrain.rWagonsBr[j].upperSeats[k].available = false;
		}
		for (int k = 0; k < 27; k++) {
			bTrain.rWagonsBr[j].lowerSeats[k].id = seatCount + 1;
			seatCount++;
			bTrain.rWagonsBr[j].lowerSeats[k].available = false;
		}
	}
	seatCount = 0;
	for (int j = 0; j < 6; j++) {
		bTrain.cWagonsBr[j].id = wagonCount + 1;
		wagonCount++;
		for (int k = 0; k < 18; k++) {
			bTrain.cWagonsBr[j].upperSeats[k].id = k + 1;
			bTrain.cWagonsBr[j].upperSeats[k].available = true;
		}
		for (int k = 0; k < 18; k++) {
			bTrain.cWagonsBr[j].lowerSeats[k].id = seatCount + 1;
			seatCount++;
			bTrain.cWagonsBr[j].lowerSeats[k].available = true;
		}
	}
	seatCount = 0;
	for (int j = 0; j < 2; j++) {
		bTrain.svWagonsBr[j].id = wagonCount + 1;
		wagonCount++;
		for (int k = 0; k < 18; k++) {
			bTrain.svWagonsBr[j].regularSeats[k].id = k + 1;
			bTrain.svWagonsBr[j].regularSeats[k].available = true;
		}
	}
	wagonCount = 0;

	sTrain.id = rand() % 100 + 1;
	sTrain.route[0] = "Station 1";
	sTrain.route[1] = "Station 4";
	for (int j = 0; j < 8; j++) {
		sTrain.rWagonsSw[j].id = j + 1;
		wagonCount++;
		for (int k = 0; k < 27; k++) {
			sTrain.rWagonsSw[j].upperSeats[k].id = k + 1;
			seatCount++;
			sTrain.rWagonsSw[j].upperSeats[k].available = true;
		}
		for (int k = 0; k < 27; k++) {
			sTrain.rWagonsSw[j].lowerSeats[k].id = seatCount + 1;
			seatCount++;
			sTrain.rWagonsSw[j].lowerSeats[k].available = true;
		}
	}
	seatCount = 0;
	for (int j = 0; j < 4; j++) {
		sTrain.cWagonsSw[j].id = wagonCount + 1;
		wagonCount++;
		for (int k = 0; k < 18; k++) {
			sTrain.cWagonsSw[j].upperSeats[k].id = k + 1;
			sTrain.cWagonsSw[j].upperSeats[k].available = true;
		}
		for (int k = 0; k < 18; k++) {
			sTrain.cWagonsSw[j].lowerSeats[k].id = seatCount + 1;
			seatCount++;
			sTrain.cWagonsSw[j].lowerSeats[k].available = true;
		}
	}
	seatCount = 0;
	wagonCount = 0;
}

void RailTicketOffice::print()
{
	std::cout << gr.lTrain[0].id << std::endl;
	for (int i = 0; i < 8; i++) {
		std::cout << gr.lTrain[0].wagons[i].id << std::endl;
	}
	for (int i = 0; i < 100; i++) {
		std::cout << gr.lTrain[0].wagons[0].regularSeats[i].id << " - " << gr.lTrain[0].wagons[0].regularSeats[i].available << std::endl;
	}
}

void RailTicketOffice::orderAccept(Date _date, int _trainID, int _wagonID, int _wagonType, FullName _name, int _counter, std::string _stationDeparture, std::string _stationArrival)
{
	tickets[_counter].date.day = _date.day;
	tickets[_counter].date.month = _date.month;
	tickets[_counter].date.year = _date.year;
	tickets[_counter].trainID = _trainID;
	tickets[_counter].wagonID = _wagonID;
	tickets[_counter].wagonType = _wagonType;
	tickets[_counter].name.name = _name.name;
	tickets[_counter].name.surname = _name.surname;
	tickets[_counter].name.patronymic = _name.patronymic;
	tickets[_counter].stationDeparture = _stationDeparture;
	tickets[_counter].stationArrival = _stationArrival;
}

bool RailTicketOffice::orderCheckAvailability(int _counter, int _wagonType)
{
	for (int i = 0; i < 3; i++) {
		if (tickets[_counter].trainID == gr.lTrain[i].id) {
			for (int j = 0; j < 8; j++) {
				for (int k = 0; k < 100; k++) {
					if (gr.lTrain[i].wagons[j].regularSeats[k].available == true)
						return true;
				}
			}
		}
	}

	int wagonCount = 0;
	int seatCount = 0;

	if (tickets[_counter].trainID == gr.bTrain.id) {
		for (int j = 0; j < 4; j++) {
			wagonCount++;
			for (int k = 0; k < 27; k++) {
				if (gr.bTrain.rWagonsBr[j].upperSeats[k].available == true)
					return true;
				seatCount++;
			}
			for (int k = 0; k < 27; k++) {
				if (gr.bTrain.rWagonsBr[j].lowerSeats[k].available == true)
					return true;
				seatCount++;
			}
		}
		seatCount = 0;
		for (int j = 0; j < 6; j++) {
			wagonCount++;
			for (int k = 0; k < 18; k++) {
				if (gr.bTrain.cWagonsBr[j].upperSeats[k].available == true)
					return true;
			}
			for (int k = 0; k < 18; k++) {
				if (gr.bTrain.cWagonsBr[j].lowerSeats[k].available == true)
					return true;
				seatCount++;
			}
		}
		seatCount = 0;
		for (int j = 0; j < 2; j++) {
			wagonCount++;
			for (int k = 0; k < 18; k++) {
				if (gr.bTrain.svWagonsBr[j].regularSeats[k].available == true)
					return true;
			}
		}
		wagonCount = 0;
	}

	if (tickets[_counter].trainID == gr.sTrain.id) {
		for (int j = 0; j < 8; j++) {
			wagonCount++;
			for (int k = 0; k < 27; k++) {
				if (gr.bTrain.rWagonsSw[j].upperSeats[k].available == true)
					return true;
				seatCount++;
			}
			for (int k = 0; k < 27; k++) {
				if (gr.bTrain.rWagonsSw[j].lowerSeats[k].available == true)
					return true;
				seatCount++;
			}
		}
		seatCount = 0;
		for (int j = 0; j < 4; j++) {
			wagonCount++;
			for (int k = 0; k < 18; k++) {
				if (gr.bTrain.cWagonsSw[j].upperSeats[k].available == true)
					return true;
			}
			for (int k = 0; k < 18; k++) {
				if (gr.bTrain.cWagonsSw[j].lowerSeats[k].available == true)
					return true;
				seatCount++;
			}
		}
		seatCount = 0;
		wagonCount = 0;
	}

	return false;
}
/*bool RailTicketOffice::orderCheckSeatAvailability(int _counter)
{
	if (tickets[_counter].trainID == gr.lTrain[0].id) {
		if (gr.lTrain[0].wagons[tickets[_counter].wagonID - 1].regularSeats[tickets[_counter].seatID - 1].available == false)
			return false;
	}
	if (tickets[_counter].trainID == gr.lTrain[1].id) {
		if (gr.lTrain[1].wagons[tickets[_counter].wagonID - 1].regularSeats[tickets[_counter].seatID - 1].available == false)
			return false;
	}
	if (tickets[_counter].trainID == gr.lTrain[2].id) {
		if (gr.lTrain[2].wagons[tickets[_counter].wagonID - 1].regularSeats[tickets[_counter].seatID - 1].available == false)
			return false;
	}
	if (tickets[_counter].trainID == gr.bTrain.id) {
		if (tickets[_counter].wagonID <= 2) {
				if (gr.bTrain.svWagons[tickets[_counter].wagonID - 1].regularSeats[tickets[_counter].seatID - 1].available == false)
					return false;
		}
		else if (tickets[_counter].wagonID > 2 && tickets[_counter].wagonID <= 8) {
			if (tickets[_counter].seatID <= 18) {
				if (gr.bTrain.cWagons[tickets[_counter].wagonID - 3].upperSeats[tickets[_counter].seatID - 1].available == false)
					return false;
			}
			if (tickets[_counter].seatID > 18) {
				if (gr.bTrain.cWagons[tickets[_counter].wagonID - 3].lowerSeats[tickets[_counter].seatID - 1].available == false)
					return false;
			}
		}
		else if (tickets[_counter].wagonID > 8 && tickets[_counter].wagonID <= 12) {
			if (tickets[_counter].seatID <= 27) {
				if (gr.bTrain.rWagons[tickets[_counter].wagonID - 9].upperSeats[tickets[_counter].seatID - 1].available == false)
					return false;
			}
			if (tickets[_counter].seatID > 27) {
				if (gr.bTrain.rWagons[tickets[_counter].wagonID - 9].lowerSeats[tickets[_counter].seatID - 1].available == false)
					return false;
			}
		}
	}
	if (tickets[_counter].trainID == gr.sTrain.id) {
		if (tickets[_counter].wagonID <= 2) {
			if (tickets[_counter].seatID <= 18) {
				if (gr.bTrain.cWagons[tickets[_counter].wagonID - 1].upperSeats[tickets[_counter].seatID - 1].available == false)
					return false;
			}
			if (tickets[_counter].seatID > 18) {
				if (gr.bTrain.cWagons[tickets[_counter].wagonID - 1].lowerSeats[tickets[_counter].seatID - 1].available == false)
					return false;
			}
		}
		else if (tickets[_counter].wagonID > 2 && tickets[_counter].wagonID <= 8) {
			if (tickets[_counter].seatID <= 27) {
				if (gr.bTrain.rWagons[tickets[_counter].wagonID - 5].upperSeats[tickets[_counter].seatID - 1].available == false)
					return false;
			}
			if (tickets[_counter].seatID > 27) {
				if (gr.bTrain.rWagons[tickets[_counter].wagonID - 5].lowerSeats[tickets[_counter].seatID - 1].available == false)
					return false;
			}
		}
	}

	return true;
}*/


void RailTicketOffice::orderReserveSeats(int _counter, int _wagonID, int _seatID)
{
	tickets[_counter].seatID = _seatID;

	for (int i = 0; i < 3; i++) {
		if (tickets[_counter].trainID == gr.lTrain[i].id) {
			gr.lTrain[i].wagons[_wagonID].regularSeats[_seatID].available = false;
		}
	}

	if (tickets[_counter].trainID == gr.bTrain.id) {
		if(tickets[_counter].wagonType == 1 && _seatID <= 27)
			gr.bTrain.rWagonsBr[_wagonID].upperSeats[_seatID].available = false;
		else if(tickets[_counter].wagonType == 1 && _seatID > 27)
			gr.bTrain.rWagonsBr[_wagonID].lowerSeats[_seatID].available = false;
		else if (tickets[_counter].wagonType == 2 && _seatID <= 18)
			gr.bTrain.cWagonsBr[_wagonID].upperSeats[_seatID].available = false;
		else if (tickets[_counter].wagonType == 2 && _seatID > 18)
			gr.bTrain.cWagonsBr[_wagonID].lowerSeats[_seatID].available = false;
		else if (tickets[_counter].wagonType == 3 && _seatID <= 18)
			gr.bTrain.svWagonsBr[_wagonID].regularSeats[_seatID].available = false;

	}

	if (tickets[_counter].trainID == gr.sTrain.id) {
		if (tickets[_counter].wagonType == 1 && _seatID <= 27)
			gr.bTrain.rWagonsSw[_wagonID].upperSeats[_seatID].available = false;
		else if (tickets[_counter].wagonType == 1 && _seatID > 27)
			gr.bTrain.rWagonsSw[_wagonID].lowerSeats[_seatID].available = false;
		else if (tickets[_counter].wagonType == 2 && _seatID <= 18)
			gr.bTrain.cWagonsSw[_wagonID].upperSeats[_seatID].available = false;
		else if (tickets[_counter].wagonType == 2 && _seatID > 18)
			gr.bTrain.cWagonsSw[_wagonID].lowerSeats[_seatID].available = false;
	}

}

int RailTicketOffice::orderCountPrice(int _counter)
{
	int ticketPrice = 0;

	for (int i = 0; i < 3; i++) {
		if (tickets[_counter].trainID == gr.lTrain[i].id) {
			ticketPrice += 500;

			return ticketPrice;
		}
	}

	if (tickets[_counter].trainID == gr.bTrain.id) {
		if (tickets[_counter].wagonType == 1) {
			ticketPrice += 250;
			return ticketPrice;
		}
		else if (tickets[_counter].wagonType == 2) {
			ticketPrice += 350;
			return ticketPrice;
		}
		else if (tickets[_counter].wagonType == 3) {
			ticketPrice += 100;
			return ticketPrice;
		}

	}

	if (tickets[_counter].trainID == gr.sTrain.id) {
		if (tickets[_counter].wagonType == 1) {
			ticketPrice += 250;
			return ticketPrice;
		}
		else if (tickets[_counter].wagonType == 2) {
			ticketPrice += 350;
			return ticketPrice;
		}
	}

	return 0;
}

void RailTicketOffice::orderCancel(int _counter)
{
	tickets[_counter].date.day = 1;
	tickets[_counter].date.month = 1;
	tickets[_counter].date.year = 1989;
	tickets[_counter].trainID = 0;
	tickets[_counter].wagonID = 0;
	tickets[_counter].wagonType = 0;
	tickets[_counter].name.name = "Михаил";
	tickets[_counter].name.surname = "ФУНДАМЕНТ";
	tickets[_counter].name.patronymic = "Павлович";
	tickets[_counter].stationDeparture = "Кринж";
	tickets[_counter].stationArrival = "База";
}

std::string RailTicketOffice::orderFormCheque(int _counter, int _counter2)
{
	std::string tempString[4];
	std::string tempString2;

	if (tickets[_counter].wagonType == 0) {
		tempString2 = "Ласточка";
	}
	else if (tickets[_counter].wagonType == 1) {
		tempString2 = "Купе";
	}
	else if (tickets[_counter].wagonType == 2) {
		tempString2 = "Плацкарт";
	}
	else if (tickets[_counter].wagonType == 3) {
		tempString2 = "Сидячий";
	}


	tempString[0] = std::to_string(tickets[_counter].date.day) + "-" + std::to_string(tickets[_counter].date.month) + "-" + std::to_string(tickets[_counter].date.year);
	tempString[1] = tickets[_counter].name.surname + '-' + tickets[_counter].name.name + '-' + tickets[_counter].name.patronymic;
	tempString[2] = std::to_string(tickets[_counter].trainID) + '-' + std::to_string(tickets[_counter].wagonID) + '-' + std::to_string(tickets[_counter].seatID) + '-' + tempString2;
	tempString[3] = tickets[_counter].stationDeparture + '-' + tickets[_counter].stationArrival;

	return tempString[_counter2];
}

int RailTicketOffice::getTrainID(int _traintype, int _counter)
{
	if (_traintype == 0) {
		return gr.lTrain[_counter].id;
	}
	else if (_traintype == 1) {
		return gr.bTrain.id;
	}
	else if (_traintype == 2) {
		return gr.sTrain.id;
	}
	return 0;
}

std::string RailTicketOffice::getStation(int _traintype, int _counter, int _stationtype)
{
	if (_traintype == 0 && _stationtype == 0) {
		return gr.lTrain[_counter].route[1];
	}
	else if (_traintype == 1 && _stationtype == 0) {
		return gr.bTrain.route[1];
	}
	else if (_traintype == 2 && _stationtype == 0) {
		return gr.sTrain.route[1];
	}
	if (_traintype == 0 && _stationtype == 1) {
		return gr.lTrain[_counter].route[0];
	}
	else if (_traintype == 1 && _stationtype == 1) {
		return gr.bTrain.route[0];
	}
	else if (_traintype == 2 && _stationtype == 1) {
		return gr.sTrain.route[0];
	}
	return std::string();
}

void RailTicketOffice::print2(int _counter)
{
	std::cout << tickets[_counter].date.day << "-" << tickets[_counter].date.month << "-" << tickets[_counter].date.year << std::endl;
	std::cout << tickets[_counter].name.surname << "-" << tickets[_counter].name.name << "-" << tickets[_counter].name.patronymic << std::endl;
	std::cout << tickets[_counter].trainID << "-" << tickets[_counter].wagonID << "-" << tickets[_counter].seatID << "-" << tickets[_counter].wagonType << std::endl;
	std::cout << tickets[_counter].stationDeparture << "-" << tickets[_counter].stationArrival << std::endl;
}

void Lastochka::test_func()
{
	
}
