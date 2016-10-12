#include <iostream>
#include <cstdlib>
#include <string>
#include "Address.h"
#include "Date.h"

//TODO : Faire les vérifications lors des setters et des données rentrées

class Person {
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	Date birthDate;
	Address address;
	Person() {}

public:
	Person(std::string firstName, std::string lastName, Address address);
	~Person();

	std::string getFirstName();
	std::string getLastName();
	std::string getNickName();
	std::string getPhoneNumber();
	Date getBirthDate();
	Address getAddress();

	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setNickName(std::string nickName);
	void setPhoneNumber(std::string phoneNumber);
	void setBirthDate(Date birthDate);
	void setAddress(Address address);

	void printPerson();
};
