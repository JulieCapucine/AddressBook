#include "Person.h"

Person::Person(string firstName, string lastName, Address address) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->address = address;

	// These datas are easy to identify, so we can see if the user enter them or not
	this->birthDate = "00/00/00";
	this->nickName = "";
	this->phoneNumber = "";
}

Person::~Person() {}

string Person::getFirstName() { return this->firstName; }
string Person::getLastName() { return this->lastName; }
string Person::getNickName() { return this->nickName; }
string Person::getPhoneNumber() { return this->phoneNumber; }
string Person::getBirthDate() { return this->birthDate; }
Address Person::getAddress() { return this->address; }

void Person::setFirstName(string firstName) { this->firstName = firstName; }
void Person::setLastName(string lastName) { this->lastName = lastName; }
void Person::setNickName(string nickName) { this->nickName = nickName; }
void Person::setPhoneNumber(string phoneNumber) { this->phoneNumber = phoneNumber; }
void Person::setBirthDate(string birthDate) { this->birthDate = birthDate; }
void Person::setAddress(Address address) { this->address = address; }

void Person::printPerson() {
	cout << this->firstName;
	if (nickName != "")
        cout << " \"" << this->nickName << "\"";
    cout << " " << this->lastName << endl;
    if (birthDate != "00/00/00")
        cout << this->birthDate << endl;
    if (phoneNumber != "")
        cout << this->phoneNumber << endl;
	this->address.printAddress();
}

unsigned int Person::isNickNamed(string nickName) {
    if (nickName == "")
        return 0;
    if (this->nickName == nickName)
        return 1;
    return 0;
}

unsigned int Person::isNamed(string firstName, string lastName) {
    if (this->firstName == firstName && this->lastName == lastName)
        return 1;
    return 0;
}

string Person::formate() {
    string result = "";
    result += this->firstName + ":" + this->nickName + ":" + this->lastName + "\n";
    result += this->address.formate() + "\n";
    result += this->phoneNumber + ":";
    result += this->birthDate;
    return result;
}

unsigned int Person::editFirstName(){
    string response;
    cout << "Enter new first name : ";
    cin >> response;
    if (response == "")
        return 0;
    this->setFirstName(response);
    return 1;
}

unsigned int Person::editLastName(){
    string response;
    cout << "Enter new last name : ";
    cin >> response;
    if (response == "")
        return 0;
    this->setLastName(response);
    return 1;
}

unsigned int Person::editNickName(){
    string response;
    cout << "Enter new nickname : ";
    cin >> response;
    if (response == "")
        return 0;
    this->setNickName(response);
    return 1;
}

unsigned int Person::editPhoneNumber(){
    string response;
    cout << "Enter new phone number : ";
    cin >> response;
    if (response == "")
        return 0;
    this->setPhoneNumber(response);
    return 1;
}

unsigned int Person::editAddress(){
    string city, country, streetName, streetNumber;
    cout << "New address : " << endl;

    cout << "Enter city : ";
    cin >> city;
    if (city == "")
        return 0;

    cout << "Enter country : ";
    cin >> country;
    if (country == "")
        return 0;

    cout << "Enter street number : ";
    cin >> streetNumber;
    if (streetNumber == "")
        return 0;

    cout << "Enter street name : ";
    cin >> streetName;
    if (streetName == "")
        return 0;

    Address address = Address(streetNumber, streetName, city, country);
    this->setAddress(address);
    return 1;
}

unsigned int Person::editBirthDate(){
    //TODO : Verification on the date validity
    string birthDate;
    cout << "New birthdate ? (dd/mm/yy) " << endl;
    cin >> birthDate;
    if (birthDate == "")
        return 0;
    this->setBirthDate(birthDate);
    return 1;
}
