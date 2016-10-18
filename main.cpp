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
    menu.loop(addresses);
    return 0;
}
