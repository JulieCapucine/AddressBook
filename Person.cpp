#include "Person.h"

Person::Person(std::string firstName, std::string lastName, Address address) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->address = address;

	// On met des donnees facilement identifiables pour verifier ou non si elles ont ete modifiees
	this->birthDate = Date(0, 0, 0);
	this->nickName = "";
	this->phoneNumber = "";
}
Person::~Person() {}

std::string Person::getFirstName() { return this->firstName; }
std::string Person::getLastName() { return this->lastName; }
std::string Person::getNickName() { return this->nickName; }
std::string Person::getPhoneNumber() { return this->phoneNumber; }
Date Person::getBirthDate() { return this->birthDate; }
Address Person::getAddress() { return this->address; }

void Person::setFirstName(std::string firstName) { this->firstName = firstName; }
void Person::setLastName(std::string lastName) { this->lastName = lastName; }
void Person::setNickName(std::string nickName) { this->nickName = nickName; }
void Person::setPhoneNumber(std::string phoneNumber) { this->phoneNumber = phoneNumber; }
void Person::setBirthDate(Date birthDate) { this->birthDate = birthDate; }
void Person::setAddress(Address address) { this->address = address; }

void Person::printPerson() {
	std::cout << this->firstName;
	if (nickName != "")
        std::cout << " \"" << this->nickName << "\"";
    std::cout << " " << this->lastName << std::endl;
    if (birthDate.getYear() != 0)
        this->birthDate.printDate();
    if (phoneNumber != "")
        std::cout << this->phoneNumber << std::endl;
	this->address.printAddress();
}

unsigned int Person::isNamed(std::string keyword) {
    if (this->firstName == keyword)
        return 1;
    return 0;
}
