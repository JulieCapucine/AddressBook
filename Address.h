#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <cstdlib>
#include <string>

class Address {
	std::string city;
	std::string country;
	unsigned int streetNumber;
	std::string streetName;

public:
	Address();
	Address(std::string city, std::string country, unsigned int streetNumber, std::string streetName);
	~Address();

	std::string getCity();
	std::string getCountry();
	unsigned int getStreetNumber();
	std::string getStreetName();

	void setCity(std::string city);
	void setCountry(std::string country);
	void setStreetNumber(unsigned int streetNumber);
	void setStreetName(std::string streetName);

	void printAddress();
};

#endif
