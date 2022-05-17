#include "class.h"

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

void filmLibrary::setProducer(std::string _producer)
{
	creators.producer = _producer;
}

void filmLibrary::setScreenwriter(std::string _screenwriter)
{
	creators.screenwriter = _screenwriter;
}

void filmLibrary::setComposer(std::string _composer)
{
	creators.composer = _composer;
}


void filmLibrary::setName(std::string _name)
{
	name = _name;
}

void filmLibrary::setProfit(int _profit)
{
	profit = _profit;
}

filmLibrary& filmLibrary::operator=(const filmLibrary& fl)
{
	this->name = fl.name;
	this->profit = fl.profit;

	this->creators.composer = fl.creators.composer;
	this->creators.producer = fl.creators.producer;
	this->creators.screenwriter = fl.creators.screenwriter;

	this->releaseDate.day = fl.releaseDate.day;
	this->releaseDate.month = fl.releaseDate.month;
	this->releaseDate.year = fl.releaseDate.year;

	return *this;
}

int filmLibrary::getDay()
{
	return releaseDate.day;
}

int filmLibrary::getMonth()
{
	return releaseDate.month;
}

int filmLibrary::getYear()
{
	return releaseDate.year;
}

std::string filmLibrary::getProducer()
{
	return creators.producer;
}

std::string filmLibrary::getScreenwriter()
{
	return creators.screenwriter;
}

std::string filmLibrary::getComposer()
{
	return creators.composer;
}

std::string filmLibrary::getName()
{
	return name;
}

int filmLibrary::getProfit()
{
	return profit;
}

filmLibrary::filmLibrary()
{
	name = "Placeholder";
	profit = 0;
	releaseDate.day = 1;
	releaseDate.month = 1;
	releaseDate.year = 1900;
	creators.producer = "Placeholder";
	creators.composer = "Placeholder";
	creators.screenwriter = "Placeholder";
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

std::string filmLibrary::filmStr()
{
	std::string day, month, year, profitstr;
	day = std::to_string(releaseDate.day); month = std::to_string(releaseDate.month); 
	year = std::to_string(releaseDate.year); profitstr = std::to_string(profit);
	std::string test = name + " " + creators.producer + " " + creators.screenwriter + " " + creators.composer + " " + day + " " + month + " " + year + " " + profitstr;
	return test;
}

void filmLibrary::filmSetData(std::string _name, std::string _producer, std::string _screenwriter, std::string _composer, int _day, int _month, int _year, int _profit)
{
	this->setDay(_day);
	this->setMonth(_month);
	this->setYear(_year);
	this->setProfit(_profit);
	this->setName(_name);
	this->setProducer(_producer);
	this->setScreenwriter(_screenwriter);
	this->setComposer(_composer);
}
