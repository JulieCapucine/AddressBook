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

unsigned int Person::isNickNamed(std::string nickName) {
    if (nickName == "") // Nickname pas défini
        return 0;
    if (this->nickName == nickName)
        return 1;
    return 0;
}

unsigned int Person::isNamed(std::string firstName, std::string lastName) {
    if (this->firstName == firstName && this->lastName == lastName)
        return 1;
    return 0;
}

std::string Person::toString() {
    std::string result = "";
    result += this->firstName + " ";
    if (this->nickName != "")
       result += "\"" + this->nickName + "\" ";
    result += this->lastName + "\n";
    result += this->address.toString()  + "\n";
    if (birthDate.getYear() != 0)
        result += this->birthDate.toString();
    if (phoneNumber != "")
        result += this->phoneNumber;
    return result;
}


unsigned int Person::editFirstName(){
    std::string response;
    std::cout << "Enter new first name" << std::endl;
    std::cin >> response;
    this->setFirstName(response);
    return 1;
}

unsigned int Person::editLastName(){
    std::string response;
    std::cout << "Enter new last name" << std::endl;
    std::cin >> response;
    this->setLastName(response);
    return 1;
}

unsigned int Person::editNickName(){
    std::string response;
    std::cout << "Enter new nickname" << std::endl;
    std::cin >> response;
    this->setNickName(response);
    return 1;
}

unsigned int Person::editPhoneNumber(){
    std::string response;
    std::cout << "Enter new phone number" << std::endl;
    std::cin >> response;
    this->setPhoneNumber(response);
    return 1;
}

unsigned int Person::editAddress(){
    std::string city, country, streetName, streetNumber;
    std::cout << "New address : " << std::endl;
    std::cout << "Enter city" << std::endl;
    std::cin >> city;
    std::cout << "Enter country" << std::endl;
    std::cin >> country;
    std::cout << "Enter streetNumber" << std::endl;
    std::cin >> streetNumber;
    std::cout << "Enter streetName" << std::endl;
    std::cin >> streetName;
    Address address;
    address = Address(city, country, streetNumber, streetName);
    this->setAddress(address);
    return 1;
}

unsigned int Person::editBirthDate(){
    Date birthdate;
    std::cout << "New birthdate: " << std::endl;
    int year, month, day;
    std::cout << "Enter year" << std::endl;
    std::cin >> year;
    std::cout << "enter month" << std::endl;
    std::cin >> month;
    std::cout << "Enter day" << std::endl;
    std::cin >> day;
    birthdate = Date(year, month, day);
    this->setBirthDate(birthdate);
    return 1;
}