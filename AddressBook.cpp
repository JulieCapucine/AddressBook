#include "AddressBook.h"

// Le code est horrible, c'est juste des id�es...
// Ajouter dans un std::vector : myvector.push_back(madonnee)
// Recuperer les donn�es d'un std::vector (toutes!) : myvector.data()
// R�cuperer la donn�e 1 d'un std::vector : myvector[indice]
// Recuperer taille : myvector.size()

void AddressBook::printAll(){
    // It�rateur dans un std::vector
    //for (std::vector<Person>::iterator it = this->entries.begin() ; it != this->entries.end(); ++it)
    //    *it.printPerson();
    // J'suis pas sure, �a c'est peut etre mieux :
    //for (int i = 0; i < this->entries.size(); i++)
    //    this->entries[i].printPerson();
}

std::vector<Person> AddressBook::search(std::string keyword){
    //It�rateur pour parcourir l'adressebook (voir printAll())

    // Cr�ation d'une m�thode de recherche chez Person : la personne[i] r�pond elle a ses criteres ?
    // Si oui, push_back dans result

    // return result;
}
void AddressBook::addContact(){
    // Cr�ation du contact
    //Person p;

    //push_back dans adressBook : this->push_back(p)

}
void AddressBook::removeContact(Person p){}
void AddressBook::editContact(Person p){
    // Chercher la personne et recuperer l'indice dans l'adresse book
    // Utiliser les setters de Person
}
void AddressBook::exportToFile(){}
