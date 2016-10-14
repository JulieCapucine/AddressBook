#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "AddressBook.h"

class Menu {

public:
	Menu(AddressBook addressbook) {};
	void printMenu(AddressBook addressbook);

};

#endif
