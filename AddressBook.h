#ifndef ADDRESS_BOOK_H
#define ADDRESS_BOOK_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include "Person.h"
#include "Address.h"
#include "Person.h"

class AddressBook {
	std::vector<Person> entries;

public:
    int isEmpty();
	void printAll();
	std::map<unsigned int, Person> search(std::string keyword);
	void addContact();
	void removeContact();
	void editContact(Person p);
	void exportToFile();
};

#endif
