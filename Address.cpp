#include <iostream>  
#include <cstdlib>
#include <string>  

class Address {
	std::string city;
	std::string country;
	int streetNumber;
	std::string streetName;

public:
	Address();
	Address(std::string city, std::string country, int streetNumber, std::string streetName);
	~Address();

	std::string getCity();
	std::string getCountry();
	int getStreetNumber();
	std::string getStreetName();

	void setCity(std::string city);
	void setCountry(std::string country);
	void setStreetNumber(int streetNumber);
	void setStreetName(std::string streetName);

	void printAddress();
};

Address(std::string city, std::string country, int streetNumber, std::string streetName);
~Address();
std::string getCity();
std::string getCountry();
int getStreetNumber();
std::string getStreetName();

void setCity(std::string city);
void setCountry(std::string country);
void setStreetNumber(int streetNumber);
void setStreetName(std::string streetName);

void printAddress() {
	std::cout << this->streetNumber << " " << this->streetName << std::endl;
	std::cout << this->city << ", " << this->country << std::endl;
}