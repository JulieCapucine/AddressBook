#include <iostream>
#include <map>
#include "Person.h"
#include "Address.h"
#include "AddressBook.h"
#include "Menu.h"

using namespace std;

int main()
{

    Menu menu;
    AddressBook addresses;
    menu.printMenu(addresses);
   /* cout << "Hello world!" << endl;

    addresses.addContact();
    addresses.addContact();*/
    //addresses.addContact();
    // addresses.printAll();

    /*map<unsigned int, Person> result = addresses.searchByName();
    std::map<unsigned int, Person>::iterator it;
    for (it=result.begin(); it!=result.end(); ++it) {
        std::cout << "Position AddressBook : " << it->first << endl;
        (it->second).printPerson();
    }*/
    // addresses.editContact();
    // addresses.removeContact();
    // addresses.printAll();
    return 0;
}
