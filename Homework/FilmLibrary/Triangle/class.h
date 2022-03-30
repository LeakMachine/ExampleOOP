#pragma once
#include <string>

class filmReleaseDate {
	int day;
	int month;
	int year;
public:
	filmReleaseDate();
	filmReleaseDate(int _day, int _month, int _year);

	friend class filmLibrary;
};

class filmCreators {
	std::string producer;
	std::string screenwriter;
	std::string composer;
public:
	filmCreators();
	filmCreators(std::string _producer, std::string _screenwriter, std::string _composer);

	friend class filmLibrary;
};

class filmLibrary {
	std::string name;
	filmCreators creators;
	filmReleaseDate releaseDate;
	int profit;
public:
	filmLibrary();
	filmLibrary(std::string _name, filmCreators _creators, filmReleaseDate _releaseDate, int _profit);

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
