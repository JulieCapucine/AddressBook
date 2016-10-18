#ifndef ADDRESS_BOOK_H
#define ADDRESS_BOOK_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include "Person.h"
#include "Address.h"
#include "Person.h"

using namespace std;

class AddressBook {
	vector<Person> entries;

public:
    // Return 1 if there is no entry in the AddressBook
    int isEmpty();
    // Print all the entries of the AddressBook
	void printAll();
	/* Search a person by his nickName
	Return a map<unsigned int, Person>
	The int correspond to the position of the Person in the vector entries
	We have choose to use a map because you can have two (or more) people with the same nickname*/
	map<unsigned int, Person> searchByNickName();
	// Search a person by his complete name (firstName + lastName)
	map<unsigned int, Person> searchByName();
	/* Search a person
	This function use searchByNickname and searchByName */
	map<unsigned int, Person> search();
	// Add a contact in the AddressBook
	void addContact();
	// Remove a contact of the AddressBook
	void removeContact();
	// Edit a contact stocked in the AddressBook
	void editContact();
	// Write the AddressBook in a formated file (by default, the file is named AddressBook.txt)
	void saveAddressBook();
	/* Read the AddressBook stocked in a formated file (by default, the file is named AddressBook.txt)
    Return the AddressBook newly created */
	AddressBook loadAddressBook();
};

#endif
