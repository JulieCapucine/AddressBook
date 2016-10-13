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

    /* Bon, ca a l'air un peu compliqu�, mais en fait, ce que je fais, c'est que quand je fais une recherche,
    je stocke la position de la personne concern�e dans l'addressBook, et la personne elle-m�me. Du coup, �a
    simplifie la suppression, l'�dition d'une personne.
    Y a aussi le parcours qui a l'air compliqu�, en fait l'id�e c'st juste d'utiliser un it�rateur, c'est
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
