#include "AddressBook.h"
#include "Address.h"
#include "Person.h"
#include "Date.h"
#include <iostream>
#include <string>
#include <map>

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
    std::map<unsigned int, Person> result;
    for (unsigned int i = 0; i < this->entries.size(); i++) {
      if (this->entries[i].isNamed(keyword)) // Si l'entree actuelle valide les criteres requis
        // Pour le moment, on verifie seulement si le firstname est egal au keyword entré
        result.insert(std::pair<unsigned int, Person>(i, this->entries[i]));

    }
    return result;
   // Retour : une liste de clé-valeurs, qui associe indice de la personne et personne
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

    if (this->isEmpty()){
        std::cout << "There is no contact in your address book." << std::endl;
    } else {

        std::string firstName, lastName;
        std::cout << "First name of the contact you want to delete ?" << std::endl;
        std::cin >> firstName;
        // std::cout << "Last name of the contact you want to delete  ? ";
        // std::cin >> lastName;

        std::map<unsigned int, Person> result = this->search(firstName);
       
         if (result.size() == 0) {
            std::cout << "There is no one with that name in your address book" << std::endl;
        } else {
            std::map<unsigned int, Person>::iterator it;
             std::string indicePerson;
             int indicePersonInt;
            if (result.size() == 1){
                 std::cout << "You are going to delete this person." << std::endl;
                 
                for (it=result.begin(); it!=result.end(); ++it) {// std::cout << "Last name
                    std::cout << "Person n° : " << it->first << std::endl;
                    (it->second).printPerson();
                }
                indicePersonInt = it->first + 1;
            } else {
                 std::cout << "There are several persons with that name in your address book : " << std::endl;
                for (it=result.begin(); it!=result.end(); ++it) {
                    std::cout << "Person n° : " << it->first << std::endl;
                    (it->second).printPerson();
                }
                std::cout << "Please enter the number of the person you want to delete" << std::endl;
               
                std::cin >> indicePerson;
                indicePersonInt = atoi(indicePerson.c_str());
            }

            std::cout << "You are going to delete this person." << std::endl;
            (this->entries.begin()  + indicePersonInt )->printPerson();
            std::cout << "Do you want to continue? y/n" << std::endl;
            std::string response;
            std::cin >> response;
            if (response.compare("y") == 0){
                this->entries.erase((this->entries.begin() + indicePersonInt));
                std::cout << "Contact deleted" << std::endl;
            } else {
                std::cout << "Abandon" << std::endl;
                //TODO libération de ???
            }
        }
    }
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
