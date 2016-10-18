#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "AddressBook.h"

using namespace std;

class Menu {
public:
	Menu() {}
	// Print the menu
	void printMenu();
	// Loop that manage the user choice and print the menu at each step
	void loop(AddressBook addressbook);
};

#endif
