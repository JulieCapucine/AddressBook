#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "Address.h"

using namespace std;

class Person {
	string firstName;
	string lastName;
	string nickName; // default = ""
	string phoneNumber; // default = ""
	string birthDate; // default = "00/00/00"
	Address address;
	Person() {}

public:
	Person(string firstName, string lastName, Address address);
	~Person();

	string getFirstName();
	string getLastName();
	string getNickName();
	string getPhoneNumber();
	string getBirthDate();
	Address getAddress();

	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setNickName(string nickName);
	void setPhoneNumber(string phoneNumber);
	void setBirthDate(string birthDate);
	void setAddress(Address address);

	// Print a person in the console
	void printPerson();
	/* Formate a person like this :
	firstName:nickName:lastName
	streetNumber:streetName:city:country
	phoneNumber:birthDate */
	string formate();
	// Return 1 if the person nickName is the same that the one passed in parameter
	unsigned int isNickNamed(string nickName);
	// Return 1 if the person firstName and lastName are the samed that them passed in parameter
	unsigned int isNamed(string firstName, string lastName);
	/* Change the firstName of the person, by asking the user to enter the new firstName
	Return 1 if the firstName was correctly edited */
	unsigned int editFirstName();
	// Functions below are based on the same principle that the editFirstName function
	unsigned int editLastName();
	unsigned int editNickName();
	unsigned int editPhoneNumber();
	unsigned int editBirthDate();
    unsigned int editAddress();
};

#endif
