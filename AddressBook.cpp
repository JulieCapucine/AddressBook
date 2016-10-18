#include "AddressBook.h"
#include "Date.h"

void AddressBook::printAll(){
    if (this->isEmpty()){
        std::cout << "Your address book is empty" << std::endl;
    } else {
        for (unsigned int i = 0; i < this->entries.size(); i++)
        this->entries[i].printPerson();
    }

}

std::map<unsigned int, Person> AddressBook::searchByNickName(){
    std::string nickName;
    std::cout << "Nickname : ";
    std::cin >> nickName;

    std::map<unsigned int, Person> result;
    for (unsigned int i = 0; i < this->entries.size(); i++) {
      if (this->entries[i].isNickNamed(nickName))
        result.insert(std::pair<unsigned int, Person>(i, this->entries[i]));
    }
    return result;
}

std::map<unsigned int, Person> AddressBook::searchByName(){
    std::string firstName, lastName;
    std::cout << "First name : ";
    std::cin >> firstName;
    std::cout << "Last name : ";
    std::cin >> lastName;

    std::map<unsigned int, Person> result;
    for (unsigned int i = 0; i < this->entries.size(); i++) {
      if (this->entries[i].isNamed(firstName, lastName))
        result.insert(std::pair<unsigned int, Person>(i, this->entries[i]));
    }
    return result;
}

std::map<unsigned int, Person> AddressBook::search() {
    std::cout << "Do you want to find a person by his name or his nickname ?" << std::endl;
    std::cout << "1. By name \t 2. By nickname" << std::endl;
    unsigned int choice;
    std::cin >> choice;

    std::map<unsigned int, Person> result;
    if (choice == 1) {
        std::cout << "Type informations of the contact you want to find" << std::endl;
        result = searchByName();
    } else if (choice == 2) {
        std::cout << "Type informations of the contact you want to find" << std::endl;
        result = searchByName();
    } else {
        std::cout << "You have to type 1 or 2.";
    }
    return result;
}

void AddressBook::addContact(){
    // Possible amelioration : cin don't like space, so we may have to use an other method to get user entries...

    // Creation contact
    std::string firstName, lastName;
    std::cout << "First name ? ";
    std::cin >> firstName;
    std::cout << "Last name ? ";
    std::cin >> lastName;

    // Creation adresse du contact
    std::string city, country, streetName, streetNumber;
    std::cout << "Country ? ";
    std::cin >> country;
    std::cout << "City ? ";
    std::cin >> city;
    std::cout << "Street number ?";
    std::cin >> streetNumber;
    std::cout << "Street name ?";
    std::cin >> streetName;

    Address a = Address(city, country, streetNumber, streetName);
    Person p = Person(firstName, lastName, a);

    this->entries.push_back(p);
}

void AddressBook::removeContact(){
    if (this->isEmpty()){
        std::cout << "There is no contact in your address book." << std::endl;
    } else {
        std::cout << "Let's find the contact you want to delete" << std::endl;
        std::map<unsigned int, Person> result = this->search();

        if (result.size() == 0) {
            std::cout << "There is no one with that name or nickname in your address book." << std::endl;
        } else {
            std::map<unsigned int, Person>::iterator it = result.begin();
            std::string indicePerson;
            int indicePersonInt = it->first;
            if (result.size() != 1) {
                std::cout << "There are several persons with that name in your address book. " << std::endl;
                for (it=result.begin(); it!=result.end(); ++it) {
                    std::cout << "Person n° : " << std::endl;
                    std::cout << it->first << std::endl;
                    (it->second).printPerson();
                }
                std::cout << "Please enter the number of the person you want to delete" << std::endl;

                std::cin >> indicePerson;
                indicePersonInt = atoi(indicePerson.c_str());
            }

            std::cout << "You are going to delete this person." << std::endl;
            (this->entries.begin() + indicePersonInt)->printPerson();
            std::cout << "Do you want to continue? y/n" << std::endl;
            std::string response;
            std::cin >> response;
            if (response.compare("y") == 0){
                this->entries.erase((this->entries.begin() + indicePersonInt));
                std::cout << "Contact deleted" << std::endl;
            } else {
                std::cout << "Abandon" << std::endl;
            }
        }
    }
}

void AddressBook::editContact(){
    std::cout << "Let's find the person you want to modify";
    std::map<unsigned int, Person> result = this->search();

    std::map<unsigned int, Person>::iterator it = result.begin();
    std::string indicePerson;
    int indicePersonInt = it->first;
    if (result.size() == 0) //Peut etre mettre ça dans la fonction search plutot, c'est plus logique...
        std::cout << "There is no one with that name or nickname in your address book." << std::endl;
    else {
           if (result.size() != 1) {
                std::cout << "There are several persons with that name in your address book. " << std::endl;
                for (it=result.begin(); it!=result.end(); ++it) {
                    std::cout << "Person n° : " << std::endl;
                    std::cout << it->first << std::endl;
                    (it->second).printPerson();
                }
                std::cout << "Please enter the number of the person you want to delete" << std::endl;

                std::cin >> indicePerson;
                indicePersonInt = atoi(indicePerson.c_str());
            }
            std::cout << "You are going to edit this person." << std::endl;
            (this->entries.begin()  + indicePersonInt )->printPerson();
            std::cout << "Do you want to continue? y/n" << std::endl;

            std::string response;
            std::cin >> response;
            if (response.compare("y") == 0){
                unsigned int choice;
                std::cout << "What do you want to edit ?" << std::endl;
                std::cout << "1. Firstname \t2. Lastname \t3. Nickname \t4. Phone number \t5. Address \t6. Birthdate" << std::endl;
                std::cin >> choice;
                std::string response, city, country, streetName, streetNumber;
                Date birthdate;
                Address address;
                switch (choice) {
                    case 1 :
                        std::cout << "Enter new first name" << std::endl;
                        std::cin >> response;
                        this->entries[indicePersonInt].setFirstName(response);
                        break;
                    case 2 :
                        std::cout << "Enter new last name" << std::endl;
                        std::cin >> response;
                        this->entries[indicePersonInt].setLastName(response);
                        break;
                    case 3 :
                        std::cout << "Enter new nickname" << std::endl;
                        std::cin >> response;
                        this->entries[indicePersonInt].setNickName(response);
                        break;
                    case 4 :
                        std::cout << "Enter new phone number" << std::endl;
                        std::cin >> response;
                        this->entries[indicePersonInt].setPhoneNumber(response);
                        break;
                    case 5 :
                        std::cout << "New address : " << std::endl;
                        std::cout << "Enter city" << std::endl;
                        std::cin >> city;
                        std::cout << "Enter country" << std::endl;
                        std::cin >> country;
                        std::cout << "Enter streetNumber" << std::endl;
                        std::cin >> streetNumber;
                        std::cout << "Enter streetName" << std::endl;
                        std::cin >> streetName;
                        address = Address(city, country, streetNumber, streetName);
                        this->entries[indicePersonInt].setAddress(address);
                        break;
                    case 6 :
                        std::cout << "New birthdate: " << std::endl;
                        int year, month, day;
                        std::cout << "Enter year" << std::endl;
                        std::cin >> year;
                        std::cout << "enter month" << std::endl;
                        std::cin >> month;
                        std::cout << "Enter day" << std::endl;
                        std::cin >> day;
                        birthdate = Date(year, month, day);
                        this->entries[indicePersonInt].setBirthDate(birthdate);
                        break;
                    default:
                        std::cout << "Oups! No function under that number" << std::endl;
                        break;
                }
            } else {
                std::cout << "Abandon" << std::endl;
            }
    }
}
void AddressBook::exportToFile(){
    std::cout << "Your address book will be exported in addressBook.txt." << std::endl;
    std::ofstream file;
    file.open("adressBook.txt");
    for (unsigned int i = 0; i < this->entries.size(); i++) {
          file << this->entries[i].toString();
          file << "\n";
    }
    file.close();
    std::cout << "Address Book exported." << std::endl;
}

int AddressBook::isEmpty() {
    if (this->entries.size() == 0)
        return 1;
    return 0;
}
