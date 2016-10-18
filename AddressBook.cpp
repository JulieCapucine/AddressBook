#include "AddressBook.h"

void AddressBook::printAll(){
    if (this->isEmpty()){
        cout << "Your address book is empty." << endl;
    } else {
        for (unsigned int i = 0; i < this->entries.size(); i++) {
            this->entries[i].printPerson();
            cout << "\n" << endl;
        }
    }
}

map<unsigned int, Person> AddressBook::searchByNickName(){
    string nickName;
    cout << "Nickname ? ";
    cin >> nickName;

    map<unsigned int, Person> result;
    for (unsigned int i = 0; i < this->entries.size(); i++) {
      if (this->entries[i].isNickNamed(nickName))
        result.insert(pair<unsigned int, Person>(i, this->entries[i]));
    }

    return result;
}

map<unsigned int, Person> AddressBook::searchByName(){
    string firstName, lastName;
    cout << "First name ? ";
    cin >> firstName;
    cout << "Last name ? ";
    cin >> lastName;

    map<unsigned int, Person> result;
    for (unsigned int i = 0; i < this->entries.size(); i++) {
      if (this->entries[i].isNamed(firstName, lastName))
        result.insert(pair<unsigned int, Person>(i, this->entries[i]));
    }

    return result;
}

map<unsigned int, Person> AddressBook::search() {
    cout << "Do you want to find a Contact by his name or his nickname ?" << endl;
    cout << "1. By his name \t 2. By his nickname" << endl;

    char choice;
    cout << "Choice : ";
    cin >> choice;
    cout << endl; // Just to pass one line

    map<unsigned int, Person> result;
    if (choice == '1') {
        result = searchByName();
    } else if (choice == '2') {
        result = searchByNickName();
    } else {
        cout << "You have to type 1 or 2.";
    }

    return result;
}

void AddressBook::addContact(){
    // Possible amelioration : cin don't like space, so we may have to use an other method to get user entries...

    string firstName, lastName;
    cout << "First name ? ";
    cin >> firstName;
    cout << "Last name ? ";
    cin >> lastName;

    string city, country, streetName, streetNumber;
    cout << "Country ? ";
    cin >> country;
    cout << "City ? ";
    cin >> city;
    cout << "Street number ? ";
    cin >> streetNumber;
    cout << "Street name ? ";
    cin >> streetName;

    Address a = Address(streetNumber, streetName, city, country);
    Person p = Person(firstName, lastName, a);

    this->entries.push_back(p);
}

void AddressBook::removeContact(){
    if (this->isEmpty()){
        cout << "There is no Contact in your address book." << endl;
    } else {
        // First, we have to choose the contact you want to delete
        cout << "Let's find the Contact you want to delete." << endl;
        map<unsigned int, Person> result = this->search();

        if (result.size() == 0) {
            cout << "There is no one with that name or that nickname in your Address Book." << endl;
        } else {
            map<unsigned int, Person>::iterator it = result.begin();
            string indicePerson;
            int indicePersonInt = it->first;
            /* If the search return more than one result, the user have to choose between many contacts.
            We display all the possible contact so he can choose the one he wants to delete */
            if (result.size() != 1) {
                cout << "\nThere are several Contacts with that name or that nickname in your address book." << endl;
                // Iteration on a map
                for (it=result.begin(); it!=result.end(); ++it) {
                    cout << "Person " << it->first << endl;
                    (it->second).printPerson();
                    cout << endl;
                }
                cout << "Please enter the number of the person you want to delete or c if you want to cancel." << endl;
                cout << "Entry : ";
                cin >> indicePerson;
                if (indicePerson == "c")
                    return;
                indicePersonInt = atoi(indicePerson.c_str());
            }

            cout << "\nYou are going to delete this person." << endl;
            (this->entries.begin() + indicePersonInt)->printPerson();

            cout << "\nDo you want to continue? y/n" << endl;
            string response;
            cin >> response;
            if (response.compare("y") == 0){
                this->entries.erase((this->entries.begin() + indicePersonInt));
                cout << "\nContact deleted." << endl;
            } else {
                cout << "\nAbandon." << endl;
            }
        }
    }
}

void AddressBook::editContact(){
    cout << "Let's find the person you want to modify." << endl;
    map<unsigned int, Person> result = this->search();

    map<unsigned int, Person>::iterator it = result.begin();
    if (result.size() == 0) {
            cout << "There is no one with that name or that nickname in your Address Book." << endl;
        } else {
            map<unsigned int, Person>::iterator it = result.begin();
            string indicePerson;
            int indicePersonInt = it->first;
            if (result.size() != 1) {
                cout << "\nThere are several Contacts with that name or that nickname in your address book." << endl;
                for (it=result.begin(); it!=result.end(); ++it) {
                    cout << "Person " << it->first << endl;
                    (it->second).printPerson();
                    cout << endl;
                }
                cout << "Please enter the number of the person you want to edit or c if you want to cancel." << endl;
                cout << "Entry : ";
                cin >> indicePerson;
                if (indicePerson == "c")
                    return;
                indicePersonInt = atoi(indicePerson.c_str());
            }
            cout << "\nYou are going to edit this person." << endl;
            (this->entries.begin()  + indicePersonInt )->printPerson();

            cout << "\nDo you want to continue? y/n" << endl;
            string response;
            cin >> response;
            if (response.compare("y") == 0){
                char choice;
                while (choice != 'q') {
                    cout << "\nWhat do you want to edit ? To quit, type q" << endl;
                    cout << "1. Firstname \t2. Lastname \t3. Nickname \n4. Phone number \t5. Address \t6. Birthdate" << endl;
                    cin >> choice;
                    int success;
                    switch (choice) {
                        case '1' :
                            success = this->entries[indicePersonInt].editFirstName();
                            break;
                        case '2' :
                            success = this->entries[indicePersonInt].editLastName();
                            break;
                        case '3' :
                            success = this->entries[indicePersonInt].editNickName();
                            break;
                        case '4' :
                            success = this->entries[indicePersonInt].editPhoneNumber();
                            break;
                        case '5' :
                            success = this->entries[indicePersonInt].editAddress();
                            break;
                        case '6' :
                            success = this->entries[indicePersonInt].editBirthDate();
                            break;
                        case 'q':
                            cout << "Edition closed." << endl;
                            break;
                        default:
                            cout << "Oups! No function under that number" << endl;
                            break;
                    }
                    if (!success)
                        cout << "Sorry but the edit failed. Maybe you have enter a empty line or a bad format date (dd/mm/yy)." << endl;
                }
            } else {
                cout << "Abandon." << endl;
            }
    }
}

void AddressBook::saveAddressBook(){
    cout << "Saving address book." << endl;
    if (this->isEmpty())
       cout << "Error : Your address book is empty." << endl;
    else {
        ofstream file;
        file.open("AddressBook.txt");
        for (unsigned int i = 0; i < this->entries.size(); i++) {
              file << this->entries[i].formate();
              file << "\n";
        }
        file.close();
        cout << "Address book saved." << endl;
    }
}

AddressBook AddressBook::loadAddressBook() {
    AddressBook ab;
    char response;
    cout << "You are going to load your address book. This will erase your current AddressBook.\nDo you want to continue ? (y/n)" << endl;
    cin >> response;
    if (response == 'y') {
        ifstream file ("AddressBook.txt");
        if (file) {
            string firstName, nickName, lastName, streetNumber, streetName, city, country, phoneNumber, birthDate;
            string buffTest;

            string line;

            while (getline(file, firstName, ':')) {
                getline(file, nickName, ':');
                getline(file, lastName);
                getline(file, streetNumber, ':');
                getline(file, streetName, ':');
                getline(file, city, ':');
                getline(file, country);
                getline(file, phoneNumber, ':');
                getline(file, birthDate);

                Address address = Address(streetNumber, streetName, city, country);
                Person p = Person(firstName, lastName, address);
                if (nickName != "")
                    p.setNickName(nickName);
                if (phoneNumber != "")
                    p.setPhoneNumber(phoneNumber);
                if (birthDate != "00/00/00")
                    p.setBirthDate(birthDate);

                ab.entries.push_back(p);
            }
        }
    }
    return ab;
}

int AddressBook::isEmpty() {
    if (this->entries.size() == 0)
        return 1;
    return 0;
}
