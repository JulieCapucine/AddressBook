#include "Menu.h"

void Menu::printMenu() {
    cout << "What do you want to do with your Address Book?\n" << endl;
	cout << "- VIEW MY CONTACTS -" << endl;
	cout << "\t0 - Display Address Book \t1 - Look for a specific Contact\n" << endl;

	cout << "- MANAGE MY CONTACTS -" << endl;
	cout << "\t2 - Add a Contact \t3 - Edit a Contact" << endl;
	cout << "\t4 - Remove a Contact\n" << endl;

	cout << "- SAVE AND LOAD -" << endl;
	cout << "\t5 - Save Address book \t6 - Load Address book\n" << endl;

	cout << "q - Quit\n" << endl;
}

void Menu::loop(AddressBook addressBook) {
    this->printMenu();

	char input;
	unsigned int result;

	cout << "Choice : ";
	cin >> input;

	cout << "\n--------------" << endl;
	switch (input){
		case '0' :
			addressBook.printAll();
			break;
        case '1':
			addressBook.search();
			break;
		case '2':
			addressBook.addContact();
			break;
        case '3':
			addressBook.editContact();
			break;
		case '4':
			addressBook.removeContact();
			break;
		case '5':
			addressBook.saveAddressBook();
			break;
        case '6':
            addressBook = addressBook.loadAddressBook();
			break;
		case 'q':
		    cout << "Goodbye !" << endl;
			exit(0);
		default:
			cout << "Oups! No fonction under that number" << endl;
			break;
	}
    cout << "--------------\n" << endl;
    this->loop(addressBook);
}
