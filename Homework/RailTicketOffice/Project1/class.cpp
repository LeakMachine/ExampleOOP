#include "class.h"

GorkyRailway::GorkyRailway()
{
	for (int i = 0; i < 3; i++) {
		lTrain[i].id = rand() % 100 + 1;
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
	//bTrain.id = rand() % 100 + 1;
	bTrain.id = 69;
	for (int j = 0; j < 4; j++) {
		bTrain.rWagons[j].id = j + 1;
		wagonCount++;
		for (int k = 0; k < 27; k++) {
			bTrain.rWagons[j].upperSeats[k].id = k + 1;
			seatCount++;
			bTrain.rWagons[j].upperSeats[k].available = false;
		}
		for (int k = 0; k < 27; k++) {
			bTrain.rWagons[j].lowerSeats[k].id = seatCount + 1;
			seatCount++;
			bTrain.rWagons[j].lowerSeats[k].available = false;
		}
	}
	seatCount = 0;
	for (int j = 0; j < 6; j++) {
		bTrain.cWagons[j].id = wagonCount + 1;
		wagonCount++;
		for (int k = 0; k < 18; k++) {
			bTrain.cWagons[j].upperSeats[k].id = k + 1;
			bTrain.cWagons[j].upperSeats[k].available = true;
		}
		for (int k = 0; k < 18; k++) {
			bTrain.cWagons[j].lowerSeats[k].id = seatCount + 1;
			seatCount++;
			bTrain.cWagons[j].lowerSeats[k].available = true;
		}
	}
	seatCount = 0;
	for (int j = 0; j < 2; j++) {
		bTrain.svWagons[j].id = wagonCount + 1;
		wagonCount++;
		for (int k = 0; k < 18; k++) {
			bTrain.svWagons[j].regularSeats[k].id = k + 1;
			bTrain.svWagons[j].regularSeats[k].available = true;
		}
	}
	wagonCount = 0;

	sTrain.id = rand() % 100 + 1;
	for (int j = 0; j < 8; j++) {
		sTrain.rWagons[j].id = j + 1;
		wagonCount++;
		for (int k = 0; k < 27; k++) {
			sTrain.rWagons[j].upperSeats[k].id = k + 1;
			seatCount++;
			sTrain.rWagons[j].upperSeats[k].available = true;
		}
		for (int k = 0; k < 27; k++) {
			sTrain.rWagons[j].lowerSeats[k].id = seatCount + 1;
			seatCount++;
			sTrain.rWagons[j].lowerSeats[k].available = true;
		}
	}
	seatCount = 0;
	for (int j = 0; j < 4; j++) {
		sTrain.cWagons[j].id = wagonCount + 1;
		wagonCount++;
		for (int k = 0; k < 18; k++) {
			sTrain.cWagons[j].upperSeats[k].id = k + 1;
			sTrain.cWagons[j].upperSeats[k].available = true;
		}
		for (int k = 0; k < 18; k++) {
			sTrain.cWagons[j].lowerSeats[k].id = seatCount + 1;
			seatCount++;
			sTrain.cWagons[j].lowerSeats[k].available = true;
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

void RailTicketOffice::orderAccept(Date _date, int _trainID, int _wagonType, FullName _name, int _counter, std::string _stationDeparture, std::string _stationArrival)
{
	tickets[_counter].date.day = _date.day;
	tickets[_counter].date.month = _date.month;
	tickets[_counter].date.year = _date.year;
	tickets[_counter].trainID = _trainID;
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
				if (gr.bTrain.rWagons[j].upperSeats[k].available == true)
					return true;
				seatCount++;
			}
			for (int k = 0; k < 27; k++) {
				if (gr.bTrain.rWagons[j].lowerSeats[k].available == true)
					return true;
				seatCount++;
			}
		}
		seatCount = 0;
		for (int j = 0; j < 6; j++) {
			wagonCount++;
			for (int k = 0; k < 18; k++) {
				if (gr.bTrain.cWagons[j].upperSeats[k].available == true)
					return true;
			}
			for (int k = 0; k < 18; k++) {
				if (gr.bTrain.cWagons[j].lowerSeats[k].available == true)
					return true;
				seatCount++;
			}
		}
		seatCount = 0;
		for (int j = 0; j < 2; j++) {
			wagonCount++;
			for (int k = 0; k < 18; k++) {
				if (gr.bTrain.svWagons[j].regularSeats[k].available == true)
					return true;
			}
		}
		wagonCount = 0;
	}

	if (tickets[_counter].trainID == gr.sTrain.id) {
		for (int j = 0; j < 8; j++) {
			wagonCount++;
			for (int k = 0; k < 27; k++) {
				if (gr.bTrain.rWagons[j].upperSeats[k].available == true)
					return true;
				seatCount++;
			}
			for (int k = 0; k < 27; k++) {
				if (gr.bTrain.rWagons[j].lowerSeats[k].available == true)
					return true;
				seatCount++;
			}
		}
		seatCount = 0;
		for (int j = 0; j < 4; j++) {
			wagonCount++;
			for (int k = 0; k < 18; k++) {
				if (gr.bTrain.cWagons[j].upperSeats[k].available == true)
					return true;
			}
			for (int k = 0; k < 18; k++) {
				if (gr.bTrain.cWagons[j].lowerSeats[k].available == true)
					return true;
				seatCount++;
			}
		}
		seatCount = 0;
		wagonCount = 0;
	}

	return false;
}

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
			gr.bTrain.rWagons[_wagonID].upperSeats[_seatID].available = false;
		else if(tickets[_counter].wagonType == 1 && _seatID > 27)
			gr.bTrain.rWagons[_wagonID].lowerSeats[_seatID].available = false;
		else if (tickets[_counter].wagonType == 2 && _seatID <= 18)
			gr.bTrain.cWagons[_wagonID].upperSeats[_seatID].available = false;
		else if (tickets[_counter].wagonType == 2 && _seatID > 18)
			gr.bTrain.cWagons[_wagonID].lowerSeats[_seatID].available = false;
		else if (tickets[_counter].wagonType == 3 && _seatID <= 18)
			gr.bTrain.svWagons[_wagonID].regularSeats[_seatID].available = false;

	}

	if (tickets[_counter].trainID == gr.sTrain.id) {
		if (tickets[_counter].wagonType == 1 && _seatID <= 27)
			gr.bTrain.rWagons[_wagonID].upperSeats[_seatID].available = false;
		else if (tickets[_counter].wagonType == 1 && _seatID > 27)
			gr.bTrain.rWagons[_wagonID].lowerSeats[_seatID].available = false;
		else if (tickets[_counter].wagonType == 2 && _seatID <= 18)
			gr.bTrain.cWagons[_wagonID].upperSeats[_seatID].available = false;
		else if (tickets[_counter].wagonType == 2 && _seatID > 18)
			gr.bTrain.cWagons[_wagonID].lowerSeats[_seatID].available = false;
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

std::string* RailTicketOffice::orderFormCheque(int _counter)
{
	std::string tempString[4];

	tempString[0] = tickets[_counter].date.day + tickets[_counter].date.month + tickets[_counter].date.year;
	tempString[1] = tickets[_counter].name.surname + '-' + tickets[_counter].name.name + '-' + tickets[_counter].name.patronymic;
	tempString[2] = tickets[_counter].trainID + '-' + tickets[_counter].wagonID + '-' + tickets[_counter].seatID + '-' + tickets[_counter].wagonType;
	tempString[3] = tickets[_counter].stationDeparture + '-' + tickets[_counter].stationArrival;

	return tempString;
}

void RailTicketOffice::print2(int _counter)
{
	std::cout << tickets[_counter].date.day << "-" << tickets[_counter].date.month << "-" << tickets[_counter].date.year << std::endl;
	std::cout << tickets[_counter].name.surname << "-" << tickets[_counter].name.name << "-" << tickets[_counter].name.patronymic << std::endl;
	std::cout << tickets[_counter].trainID << "-" << tickets[_counter].wagonID << "-" << tickets[_counter].seatID << "-" << tickets[_counter].wagonType << std::endl;
	std::cout << tickets[_counter].stationDeparture << "-" << tickets[_counter].stationArrival << std::endl;
}
