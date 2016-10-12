#include "Date.h"

Date::Date(unsigned int year) {
	this->year = year;
	this->day = 1;
	this->month = 1;
}
Date::Date(unsigned int year, unsigned int month, unsigned int day) {
	this->year = year;
	this->month = month;
	this->day = day;
}

Date::~Date() {}

unsigned int Date::getYear() {  return this->year; }
unsigned int Date::getMonth() { return this->month; }
unsigned int Date::getDay() { return this->day; }

void Date::setYear(unsigned int year) { this->year = year; }
void Date::setMonth(unsigned int month) {
	if (month > 12 && month != 0)
		this->month = month;
}
void Date::setDay(unsigned int day) {
	if (day > 31 && day != 0)
		this->day = day;
}

void Date::printDate() {
	// Day / Month / Year
	std::cout << this->day << "/" << this->month << "/" << this->year << std::endl;
}
