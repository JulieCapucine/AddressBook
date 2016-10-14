#include <iostream>
#include <map>
#include "Person.h"
#include "Date.h"
#include "Address.h"
#include "AddressBook.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    AddressBook addresses;
    addresses.addContact();
    addresses.addContact();
    //addresses.addContact();
    addresses.printAll();

    /*map<unsigned int, Person> result = addresses.searchByName();
    std::map<unsigned int, Person>::iterator it;
    for (it=result.begin(); it!=result.end(); ++it) {
        std::cout << "Position AddressBook : " << it->first << endl;
        (it->second).printPerson();
    }*/
    addresses.editContact();
    addresses.removeContact();
    addresses.printAll();
    return 0;
}
