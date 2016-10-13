#include "AddressBook.h"
#include "Address.h"
#include "Person.h"
#include "Date.h"

// Le code est horrible, c'est juste des idées...
// Ajouter dans un std::vector : myvector.push_back(madonnee)
// Recuperer les données d'un std::vector (toutes!) : myvector.data()
// Récuperer la donnée 1 d'un std::vector : myvector[indice]
// Recuperer taille : myvector.size()

void AddressBook::printAll(){
   for (unsigned int i = 0; i < this->entries.size(); i++)
      this->entries[i].printPerson();

}

std::map<unsigned int, Person> AddressBook::search(std::string keyword){
    // Voir si on peut pas faire une sorte de matrice, qui prend la Person mais aussi son indice dans l'AddressBook
    std::map<unsigned int, Person> result;
    for (unsigned int i = 0; i < this->entries.size(); i++) {
      if (this->entries[i].isNamed(keyword)) // Si l'entree actuelle valide les criteres requis
        // Pour le moment, on verifie seulement si le firstname est egal au keyword entré
        result.insert(std::pair<unsigned int, Person>(i, this->entries[i]));

    }
    return result;
}
void AddressBook::addContact(){
    // Ca fonctionne mais attention, cin aime pas les phrases avec espace
    // Il considere que c'est une validation du mot precedent, voir comment ameliorer ca

    // Creation contact
    std::string firstName, lastName;
    std::cout << "First name ? ";
    std::cin >> firstName;
    std::cout << "Last name ? ";
    std::cin >> lastName;


    // Creation adresse du contact
    /*std::string city, country, streetName;
    unsigned int streetNumber;
    std::cout << "Country ? ";
    std::cin >> country;
    std::cout << "City ? ";
    std::cin >> city;
    std::cout << "Street number ?";
    std::cin >> streetNumber;
    std::cout << "Street name ?";
    std::cin >> streetName;

    Address a = Address(city, country, streetNumber, streetName);*/
    // Ce qui est avant fonctionne, c'est juste pour eviter de tout taper pendant les tests
    Address a = Address("Meaux", "France", 4, "Rue des Tuilleries");
    Person p = Person(firstName, lastName, a);

    this->entries.push_back(p);

}
void AddressBook::removeContact(){
    //if isEmpty, ne rien faire
    // Demander qui on veut supprimer
}

void AddressBook::editContact(Person p){
    // Chercher la personne et recuperer l'indice dans l'adresse book
    // Utiliser les setters de Person
}
void AddressBook::exportToFile(){}

int AddressBook::isEmpty() {
    if (this->entries.size() == 0)
        return 1;
    return 0;
}
