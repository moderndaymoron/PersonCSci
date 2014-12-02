#include "PersonRepository.h"
#include <fstream>
#include <string>
#include <algorithm>
#include "comparer.h"
#include <iomanip>


using namespace std;

PersonRepository::PersonRepository() {
    ifstream inFile("PersonFile.txt");

    if(inFile.is_open()) {
        string  line1, line2, line3, line4;

        while(getline(inFile, line1) &&
              getline(inFile, line2) &&
              getline(inFile, line3) &&
              getline(inFile, line4)) {

            Person temp;
            temp.setName(line1);
            temp.setGender(line2);
            temp.setDayOfBirth(line3);
            temp.setDayOfDeath(line4);
            plist.push_back(temp);
        }

    } else {
        cout << "ERROR: cannot open file." << endl;
        cout << endl;
    }

    inFile.close();
}

void PersonRepository::add(Person p) {
    plist.push_back(p);

}

void PersonRepository::display() {
    if(plist.size()) {
        char ans;
        cout << "Do you want to sort it (y/n)? ";
        cin >> ans;
        cin.ignore();
        if (ans == 'y' || ans == 'Y') {
            cout << "Sort by (name/gender/date of birth/date of death)? ";
            string sortOrder;
            getline(cin, sortOrder);
            Comparer comp = Comparer(sortOrder);
            cout << endl;
            cout << "sorting...";
            try {
                cout << endl;

                       cout << endl;
                       cout.width(40);
                       cout << left << "Name";
                       cout.width(14);
                       cout << left << "Gender";
                       cout.width(14);
                       cout << left << "Year of birth";
                       cout.width(15);
                       cout << left << "Year of death" << endl;
                       cout << endl;
                sort(plist.begin(),plist.end(), comp);
                for(int i = 0; i < plist.size(); i++) {
<<<<<<< HEAD
                    cout.width(40);
                    cout << left << plist[i].name;
                    cout.width(18);
                    cout << left << plist[i].gender;
                    cout.width(15);
                    cout << left << plist[i].dayOfBirth;
                    cout.width(15);
                    cout << left << plist[i].dayOfDeath;

                    cout << endl;
=======
                    displayPerson(i);
>>>>>>> 529c2e6aab0cf04b9fc459ce6d2e0dea248fe1c3
                }
            } catch (...) {
                cout << "ERROR: Sorting failed." << endl;
                cout << endl;
            }

        } else if((ans == 'n' || ans == 'N')) {

                   cout << endl;
                   cout.width(40);
                   cout << left << "Name";
                   cout.width(14);
                   cout << left << "Gender";
                   cout.width(14);
                   cout << left << "Year of birth";
                   cout.width(20);
                   cout << left << "Year of death" << endl;
                   cout << endl;
            for(int i = 0; i < plist.size(); i++) {
<<<<<<< HEAD
                cout.width(40);
                cout << left << plist[i].name;
                cout.width(18);
                cout << left << plist[i].gender;
                cout.width(15);
                cout << left << plist[i].dayOfBirth;
                cout.width(15);
                cout << left << plist[i].dayOfDeath;
                cout << endl;

=======
                displayPerson(i);
>>>>>>> 529c2e6aab0cf04b9fc459ce6d2e0dea248fe1c3
            }
        }

    } else {
        cout << "The database is empty" << endl;
        cout << endl;
    }
}

void PersonRepository::save() {
    ofstream outFile("PersonFile.txt");

    string tempLine;

    if(outFile.is_open()) {

        for(unsigned int i = 0; i < plist.size(); i++) {
            outFile << plist[i].getName() << endl;
            outFile << plist[i].getGender() << endl;
            outFile << plist[i].getDayOfBirth() << endl;
            outFile << plist[i].getDayOfDeath() << endl;
        }

        cout << "All changes have been saved." << endl;
        cout << endl;

    } else {
        cout << "ERROR: cannot open file." << endl;
        cout << endl;
    }

    outFile.close();
}

void PersonRepository::erase() {
    string answer;
    cout << "What would you like to erase (all/specific)? ";
    getline(cin, answer);

    if (answer == "all") {
        plist.erase(plist.begin(),plist.end());
        cout << endl;
        cout << "All persons have been erased." << endl;
        cout << endl;

    } else if (answer == "specific") {
        searchSwitch(searchFor(), "erase");
    }
}

void PersonRepository::eraseLoop(string input, string word)
{
    cout << "Searching..." << endl;
    cout << endl;

    char erase;
    int index, failCounter = 0, hitCounter = 0;
    for(index = 0; index < plist.size(); index++) {
        if(input == plist[index].getName()) {
            cout << "Found at index " << index << endl;
            displayPerson(index);
            cout << "Erase?(y/n) ";

            cin >> erase;
            cin.ignore();

            if(erase == 'y' || erase == 'Y'){
                plist.erase(plist.begin()+index);
                cout << "Person erased." << endl;
                index--; //because erasing means the .size() function returns a smaller value, needs to shrink the index as required
                hitCounter++;
                cout << endl;
            }else{
                cout << "Person not erased." << endl;
                cout << endl;
            }

        } else {
            failCounter++;
        }
    }


    if ((failCounter == plist.size()) && (hitCounter == 0)) {
        cout << "ERROR: Could not find, person does not exist in database." << endl;
        cout << endl;
    }
}


void PersonRepository::search() {
<<<<<<< HEAD
    string input, word;
    char searcher;
    searcher = searchFor();

    switch(searcher){
    case 'n':
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, input);
        word = "name";
        searchLoop(input, word);
        break;
    case 'g':
        cout << "Enter gender: ";
        cin.ignore();
        getline(cin, input);
        word = "gender";
        searchLoop(input, word);
        break;
    case 'b':
        cout << "Enter year of birth: ";
        cin.ignore();
        getline(cin, input);
        word = "dayOfBirth";
        searchLoop(input, word);
        break;
    case 'd':
        cout << "Enter year of death: ";
        cin.ignore();
        getline(cin, input);
        word = "dayOfDeath";
        searchLoop(input, word);
        break;
    }
=======
    searchSwitch(searchFor(), "search");
>>>>>>> 529c2e6aab0cf04b9fc459ce6d2e0dea248fe1c3
}

void PersonRepository::searchLoop(string input, string word)
{
    int index, failCounter = 0;
    for(index = 0; index < plist.size(); index++) {
       if((word == "name" && input == plist[index].getName())
       || (word == "gender" && input == plist[index].getGender())
       || (word == "dayOfBirth" && input == plist[index].getDayOfBirth())
       || (word == "dayOfDeath" && input == plist[index].getDayOfDeath())) {

            cout << "Found at index " << index << endl;
            displayPerson(index);
            cout << endl;

        } else {
            failCounter++;

        }
    }
    if (failCounter == plist.size()) {
        cout << "ERROR: Could not find, person does not exist in database." << endl;
        cout << endl;
    }
    cout << endl;
}




double PersonRepository::getSize() {
    return plist.size();
}

void PersonRepository::displayPerson(const int index)
{
    cout << "Name:\t\t" << plist[index].getName() << endl;
    cout << "Gender:\t\t"<< plist[index].getGender() << endl;
    cout << "Date of birth:\t" << plist[index].getDayOfBirth() << endl;
    cout << "Date of death:\t" << plist[index].getDayOfDeath() << endl;
    cout << endl;

}

char PersonRepository::searchFor()
{

    char searchFor;
    cout << "enter 'n' to search for name " << endl;
    cout << "enter 'g' to search for gender " << endl;
    cout << "enter 'b' to search for birthdate " << endl;
    cout << "enter 'd' to search for deceased date " << endl;
    do {
        cin >> searchFor;
        if(!isValidSearchColumn(searchFor)) {
            cout << "Invalid command! Enter 'n' 'g' 'b' or 'd'" << endl;
        }
    } while(!isValidSearchColumn(searchFor));
    cout << endl;

    return searchFor;
}

bool PersonRepository::isValidSearchColumn(char in) {
    if (in == 'n' || in == 'g' || in == 'b' || in == 'd') {
        return true;
    }
    return false;
}

void PersonRepository::searchSwitch(char searchColumn, string searchType) {
    string input, word;
    switch(searchColumn){
        case 'n':
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, input);
            word = "name";
            if(searchType == "search") {
                searchLoop(input, word);
            } else {
                eraseLoop( input, word);
            }
            break;

        case 'g':
            cout << "Enter gender: ";
            cin.ignore();
            getline(cin, input);
            word = "gender";
            if(searchType == "search") {
                searchLoop(input, word);
            } else {
                eraseLoop( input, word);
            }
            break;

        case 'b':
            cout << "Enter year of birth: ";
            cin.ignore();
            getline(cin, input);
            word = "dayOfBirth";
            if(searchType == "search") {
                searchLoop(input, word);
            } else {
                eraseLoop( input, word);
            }
            break;

        case 'd':
            cout << "Enter year of death: ";
            cin.ignore();
            getline(cin, input);
            word = "dayOfDeath";
            if(searchType == "search") {
                searchLoop(input, word);
            } else {
                eraseLoop(input, word);
            }
            break;
    }

}
