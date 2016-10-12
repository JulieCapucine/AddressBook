#include "Person.h"

Person::Person(std::string firstName, std::string lastName, Address address) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->address = address;
	// TODO : Voir si on peut / il faut mettre à NULL le reste
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
	std::cout << this->firstName << " \"" << this->nickName << "\" " << this->lastName << std::endl;
	this->birthDate.printDate();
	std::cout << this->phoneNumber << std::endl;
	this->address.printAddress();
}
