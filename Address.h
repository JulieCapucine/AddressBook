#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Address {
	string streetNumber;
	string streetName;
    string city;
	string country;

public:
	Address();
	Address(string streetNumber, string streetName, string city, string country);
	~Address();

	string getCity();
	string getCountry();
	string getStreetNumber();
	string getStreetName();

	void setCity(string city);
	void setCountry(string country);
	void setStreetNumber(string streetNumber);
	void setStreetName(string streetName);

	// Print an address in the console
	void printAddress();
	/* Formate a address like this :
	streetNumber:streetName:city:country */
	string formate();
};

#endif
