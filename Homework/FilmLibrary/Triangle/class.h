#pragma once
#include <string>

class filmReleaseDate {
protected:
	int day;
	int month;
	int year;
public:
	friend class filmLibrary;
};

class filmCreators {
protected:
	std::string producer;
	std::string screenwriter;
	std::string composer;
public:
	friend class filmLibrary;
};

class filmLibrary {
private:
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

	void setDay(int _day);
	void setMonth(int _month);
	void setYear(int _year);
	void setProducer(std::string _producer);
	void setScreenwriter(std::string _screenwriter);
	void setComposer(std::string _composer);
	void setName(std::string _name);
	void setProfit(int _profit);

	filmLibrary& operator=(const filmLibrary& fl);


	std::string filmStr();
	void filmSetData(std::string _name, std::string _producer, std::string _screenwriter, std::string _composer, int _day, int _month, int _year, int _profit);
};
