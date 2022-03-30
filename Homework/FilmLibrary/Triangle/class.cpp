#include "class.h"

filmReleaseDate::filmReleaseDate()
{
	day = 1;
	month = 1;
	year = 1900;
}

filmReleaseDate::filmReleaseDate(int _day, int _month, int _year)
{
	day = _day;
	month = _month;
	year = _year;
}

void filmLibrary::setDay(int _day)
{
	releaseDate.day = _day;
}

void filmLibrary::setMonth(int _month)
{
	releaseDate.month = _month;
}

void filmLibrary::setYear(int _year)
{
	releaseDate.year = _year;
}

filmCreators::filmCreators()
{
	producer = "Placeholder";
	screenwriter = "Placeholder";
	composer = "Placeholder";
}

filmCreators::filmCreators(std::string _producer, std::string _screenwriter, std::string _composer)
{
	producer = _producer;
	screenwriter = _screenwriter;
	composer = _composer;
}

void filmLibrary::setProducer(std::string _producer)
{
}

void filmLibrary::setScreenwriter(std::string _screenwriter)
{
}

void filmLibrary::setComposer(std::string _composer)
{
}

filmLibrary::filmLibrary()
{
	name = "Placeholder";
	profit = 0;
}

filmLibrary::filmLibrary(std::string _name, filmCreators _creators, filmReleaseDate _releaseDate, int _profit)
{
	name = _name;
	profit = _profit;

	creators.composer = _creators.composer;
	creators.producer = _creators.producer;
	creators.screenwriter = _creators.screenwriter;

	releaseDate.day = _releaseDate.day;
	releaseDate.month = _releaseDate.month;
	releaseDate.year = _releaseDate.year;
}

void filmLibrary::setName(std::string _name)
{
}

void filmLibrary::setProfit(int _profit)
{
	profit = _profit;
}

std::string filmLibrary::filmStr()
{
	std::string day, month, year, profitstr;
	day = std::to_string(releaseDate.day); month = std::to_string(releaseDate.month); 
	year = std::to_string(releaseDate.year); profitstr = std::to_string(profit);
	std::string test = name + " " + creators.composer + " " + creators.producer + " " + creators.screenwriter + " " + day + " " + month + " " + year + " " + profitstr;
	return test;
}
