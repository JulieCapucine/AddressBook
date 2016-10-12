#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

class Date {
	unsigned int year;
	unsigned int month;
	unsigned int day;

    Date(){}

public :
	Date(unsigned int year);
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
