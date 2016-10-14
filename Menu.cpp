#include "Menu.h"

void Menu::printMenu(AddressBook addressbook){
	std::cout << "What do you want to do with your address book?" << std::endl;
	std::cout << "0 - Display address book" << std::endl;
	std::cout << "1 - Add a contact" << std::endl;
	std::cout << "2 - Remove a contact" << std::endl;
	std::cout << "3 - Look for a specific contact" << std::endl;
	std::cout << "4 - Edit a contact" << std::endl;
	std::cout << "5 - Quit" << std::endl;
	int input;
	std::cin >> input;
	switch (input){
		case 0 :
			addressbook.printAll();
			std::cout << "####################" << std::endl;
			this->printMenu(addressbook);
			break;
		case 1:
			addressbook.addContact();
			std::cout << "####################" << std::endl;
			this->printMenu(addressbook);
			break;
		case 2:
			addressbook.removeContact();
			std::cout << "####################" << std::endl;
			this->printMenu(addressbook);
			break;
		case 3:
			addressbook.search();
			std::cout << "####################" << std::endl;
			this->printMenu(addressbook);
			break;
		case 4:
			addressbook.editContact();
			std::cout << "####################" << std::endl;
			this->printMenu(addressbook);
			break;
		case 5:
			exit(0);
			break;
		default:
			std::cout << "Oups! No fonction under that number" << std::endl;
			std::cout << "####################" << std::endl;
			this->printMenu(addressbook);
			break;
	}

}
