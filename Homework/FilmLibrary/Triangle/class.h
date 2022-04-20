#pragma once
#include <string>

class filmReleaseDate {
private:
	int day;
	int month;
	int year;
public:
	friend class filmLibrary;
};

class filmCreators {
private:
	std::string producer;
	std::string screenwriter;
	std::string composer;
public:
	friend class filmLibrary;
};

class filmLibrary {
public:
	std::string name;
	filmCreators creators;
	filmReleaseDate releaseDate;
	int profit;

public:
	filmLibrary();
	filmLibrary(std::string _name, filmCreators _creators, filmReleaseDate _releaseDate, int _profit);

	int getDay();
	int getMonth();
	int getYear();
	std::string getProducer();
	std::string getScreenwriter();
	std::string getComposer();
	std::string getName();
	int getProfit();

	double helpMe();

	void setDay(int _day);
	void setMonth(int _month);
	void setYear(int _year);
	void setProducer(std::string _producer);
	void setScreenwriter(std::string _screenwriter);
	void setComposer(std::string _composer);
	void setName(std::string _name);
	void setProfit(int _profit);

	std::string filmStr();
};
