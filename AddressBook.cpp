#include "AddressBook.h"

// Le code est horrible, c'est juste des idées...
// Ajouter dans un std::vector : myvector.push_back(madonnee)
// Recuperer les données d'un std::vector (toutes!) : myvector.data()
// Récuperer la donnée 1 d'un std::vector : myvector[indice]
// Recuperer taille : myvector.size()


void AddressBook::printAll(){
    // Itérateur dans un std::vector
    //for (std::vector<Person>::iterator it = this->entries.begin() ; it != this->entries.end(); ++it)
    //    *it.printPerson();
    // J'suis pas sure, ça c'est peut etre mieux :
    //for (int i = 0; i < this->entries.size(); i++)
    //    this->entries[i].printPerson();
}

std::vector<Person> AddressBook::search(std::string keyword){
    //Itérateur pour parcourir l'adressebook (voir printAll())

    // Création d'une méthode de recherche chez Person : la personne[i] répond elle a ses criteres ?
    // Si oui, push_back dans result
    std::vector<Person> result;
    return result;
}
void AddressBook::addContact(){
    // Création du contact
    //Person p;

    //push_back dans adressBook : this->push_back(p)

}
void AddressBook::removeContact(Person p){
    //Rercherche de la personne
    //std::vector<Person> contactToRemove = AddressBook::search(p);
    //Verification que c'est la bonne personne?
    // contactToRemove(0).printPerson();
    //  std::cout << "est ce bien la personne que vous voulez supprimer? y/n" << std::endl
    // std::cin >> response 
    // if (response == "n") { ????
    // }
    // else {
    //  contactToRemove(0).~Person(); 
    // ca marche meme pas ce truc, je suis un caca
    //}



}



void AddressBook::editContact(Person p){
    // Chercher la personne et recuperer l'indice dans l'adresse book
    // Utiliser les setters de Person
}
void AddressBook::exportToFile(){}
