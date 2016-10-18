#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <cstdlib>
#include <string>

class Address {
	std::string city;
	std::string country;
	std::string streetNumber;
	std::string streetName;

public:
	Address();
	Address(std::string city, std::string country, std::string streetNumber, std::string streetName);
	~Address();

	std::string getCity();
	std::string getCountry();
	std::string getStreetNumber();
	std::string getStreetName();

	void setCity(std::string city);
	void setCountry(std::string country);
	void setStreetNumber(std::string streetNumber);
	void setStreetName(std::string streetName);

	void printAddress();
	std::string toString();
};

#endif
