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
	bTrain.id = rand() % 100 + 1;
	for (int j = 0; j < 4; j++) {
		bTrain.rWagons[j].id = j + 1;
		wagonCount++;
		for (int k = 0; k < 27; k++) {
			bTrain.rWagons[j].upperSeats[k].id = k + 1;
			seatCount++;
			bTrain.rWagons[j].upperSeats[k].available = true;
		}
		for (int k = 0; k < 27; k++) {
			bTrain.rWagons[j].lowerSeats[k].id = seatCount + 1;
			seatCount++;
			bTrain.rWagons[j].lowerSeats[k].available = true;
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

void GorkyRailway::printshit()
{
	std::cout << lTrain[0].id << std::endl;
	std::cout << lTrain[1].id << std::endl;
	std::cout << lTrain[2].id << std::endl;
	for (int i = 0; i < 8; i++) {
		std::cout << lTrain[0].wagons[i].id << std::endl;
	}
	for (int i = 0; i < 100; i++) {
		std::cout << lTrain[0].wagons[0].regularSeats[i].id << " - " << lTrain[0].wagons[0].regularSeats[i].available << std::endl;
	}
}

