#include "Menu.h"

void Menu::printMenu(AddressBook addressbook){
	std::cout << "\n \nWhat do you want to do with your address book? \n" << std::endl;
	std::cout << "0 - Display address book" << std::endl;
	std::cout << "1 - Add a contact" << std::endl;
	std::cout << "2 - Remove a contact" << std::endl;
	std::cout << "3 - Look for a specific contact" << std::endl;
	std::cout << "4 - Edit a contact" << std::endl;
	std::cout << "5 - Export Address book to file" << std::endl;
	std::cout << "q - Quit \n" << std::endl;
	char input;
	std::cin >> input;
	std::cout << "\n" << std::endl;
	switch (input){
		case '0' :
			addressbook.printAll();
			std::cout << "\n #################### \n" << std::endl;
			this->printMenu(addressbook);
			break;
		case '1':
			addressbook.addContact();
			std::cout << "\n #################### \n" << std::endl;
			this->printMenu(addressbook);
			break;
		case '2':
			addressbook.removeContact();
			std::cout << "\n #################### \n" << std::endl;
			this->printMenu(addressbook);
			break;
		case '3':
			addressbook.search();
			std::cout << "\n #################### \n" << std::endl;
			this->printMenu(addressbook);
			break;
		case '4':
			addressbook.editContact();
			std::cout << "\n #################### \n" << std::endl;
			this->printMenu(addressbook);
			break;
		case '5':
			addressbook.exportToFile();
			std::cout << "\n #################### \n" << std::endl;
			this->printMenu(addressbook);
			break;
		case 'q':
			exit(0);
			break;
		default:
			std::cout << "Oups! No fonction under that number" << std::endl;
			std::cout << "\n #################### \n" << std::endl;
			this->printMenu(addressbook);
			break;
	}

}
