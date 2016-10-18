#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "Address.h"

//TODO : Faire les vérifications lors des setters et des données rentrées

class Person {
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string birthDate;
	Address address;
	Person() {}

public:
	Person(std::string firstName, std::string lastName, Address address);
	~Person();

	std::string getFirstName();
	std::string getLastName();
	std::string getNickName();
	std::string getPhoneNumber();
	std::string getBirthDate();
	Address getAddress();

	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setNickName(std::string nickName);
	void setPhoneNumber(std::string phoneNumber);
	void setBirthDate(std::string birthDate);
	void setAddress(Address address);

	void printPerson();
	std::string formate();
	unsigned int isNickNamed(std::string nickName);
	unsigned int isNamed(std::string firstName, std::string lastName);
	unsigned int editFirstName();
	unsigned int editLastName();
	unsigned int editNickName();
	unsigned int editPhoneNumber();
	unsigned int editBirthDate();
unsigned int editAddress();
};

#endif
