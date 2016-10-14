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
	std::map<unsigned int, Person> searchByNickName();
	std::map<unsigned int, Person> searchByName();
	std::map<unsigned int, Person> search();
	void addContact();
	void removeContact();
	void editContact();
	void exportToFile();
};

#endif
