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
    addresses.addContact();
    addresses.printAll();
    cout << "#### Recherche de personnes dont le firstname est Julie ####" << endl;

    /* Bon, ca a l'air un peu compliqué, mais en fait, ce que je fais, c'est que quand je fais une recherche,
    je stocke la position de la personne concernée dans l'addressBook, et la personne elle-même. Du coup, ça
    simplifie la suppression, l'édition d'une personne.
    Y a aussi le parcours qui a l'air compliqué, en fait l'idée c'st juste d'utiliser un itérateur, c'est
    le plus simple, et c'est assez clair quand on comprend, et je sais que tu comprendras :3 */

    map<unsigned int, Person> result = addresses.search("Julie");
    std::map<unsigned int, Person>::iterator it;
    for (it=result.begin(); it!=result.end(); ++it) {
        std::cout << "Position AddressBook : " << it->first << endl;
        (it->second).printPerson();
    }

    addresses.removeContact();
    addresses.printAll();
    return 0;
}
