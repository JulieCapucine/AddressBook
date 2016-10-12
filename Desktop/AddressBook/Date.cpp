#include <iostream>  
#include <cstdlib>
#include <string>  

class Date {
	unsigned int year;
	unsigned int month;
	unsigned int day;
	
	Date() {}

public :
	Date(unsigned int year, unsigned int month = 01, unsigned int day = 01);
	Date(unsigned int year, unsigned int month, unsigned int day);
	~Date();

	unsigned int getYear();
	unsigned int getMonth();
	unsigned int getDay();

	void setYear(unsigned int year);
	void setMonth(unsigned int month);
	void setDay(unsigned int day);

	void printDate();
};

Date(unsigned int year, unsigned int month = 01, unsigned int day = 01) {
	this->year = year;
}
Date(unsigned int year, unsigned int month, unsigned int day) {
	this->year = year;
	this->month = month;
	this->day = day;
}
~Date() {}

unsigned int getYear() {  return this->year; }
unsigned int getMonth() { return this->month; }
unsigned int getDay() { return this->day; }

void setYear(unsigned int year) { this->year = year; }
void setMonth(unsigned int month) { 
	if (month > 12 && month != 0)
		this->month = month; 
}
void setDay(unsigned int day) { 
	if (day > 31 && day != 0)
		this->day = day; 
}

void printDate() {
	// Day / Month / Year
	std::cout << this->day << "/" << this->month << "/" << this->year << std::endl;
}