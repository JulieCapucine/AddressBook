#include <iostream>  
#include <cstdlib>
#include <string>  

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

Person(std::string firstName, std::string lastName, Address address) { 
	this->firstName = firstName;
	this->lastName = lastName;
	this->address = address;
	// TODO : Voir si on peut / il faut mettre à NULL le reste
}
~Person() {}

std::string getFirstName() { return this->firstName; }
std::string getLastName() { return this->lastName; }
std::string getNickName() { return this->nickName; }
std::string getPhoneNumber() { return this->phoneNumber; }
Date getBirthDate() { return this->birthDate; }
Address getAddress() { return this->address; }

void setFirstName(std::string firstName) { this->firstName = firstName; }
void setLastName(std::string lastName) { this->lastName = lastName; }
void setNickName(std::string nickName) { this->nickName = nickName; }
void setPhoneNumber(std::string phoneNumber) { this->phoneNumber = phoneNumber; }
void setBirthDate(Date birthDate) { this->birthDate = birthDate; }
void setAddress(Address address) { this->address = address; }

void printPerson() {
	std::cout << this->firstName << " \"" << this->nickName << "\" " << this->lastName << std::endl;
	this->birthDate.printDate();
	std::cout << this->phoneNumber << std::endl;
	this->adress.printAddress();
}