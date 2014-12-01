#include "PersonRepository.h"
#include <fstream>
#include <string>
#include <algorithm>
#include "comparer.h"

using namespace std;

PersonRepository::PersonRepository() {
    plist;
    ifstream inFile("PersonFile.txt");

    if(inFile.is_open()) {
        string  line1, line2, line3, line4;

        while(getline(inFile, line1) &&
              getline(inFile, line2) &&
              getline(inFile, line3) &&
              getline(inFile, line4)) {

            Person temp;
            temp.name = line1;
            temp.gender = line2;
            temp.dayOfBirth = line3;
            temp.dayOfDeath = line4;
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
            cin.ignore();
            getline(cin, sortOrder);
            Comparer comp = Comparer(sortOrder);

            try {
                sort(plist.begin(),plist.end(), comp);
                for(int i = 0; i < plist.size(); i++) {
                    cout << "Name:\t\t" << plist[i].name << endl;
                    cout << "Gender:\t\t"<< plist[i].gender << endl;
                    cout << "Date of birth:\t" << plist[i].dayOfBirth << endl;
                    cout << "Date of death:\t" << plist[i].dayOfDeath << endl;
                    cout << endl;
                }
            } catch (...) {
                cout << "ERROR: Sorting failed." << endl;
                cout << endl;
            }
        } else if((ans == 'n' || ans == 'N')) {
            for(int i = 0; i < plist.size(); i++) {
                cout << "Name:\t\t" << plist[i].name << endl;
                cout << "Gender:\t\t"<< plist[i].gender << endl;
                cout << "Date of birth:\t" << plist[i].dayOfBirth << endl;
                cout << "Date of death:\t" << plist[i].dayOfDeath << endl;
                cout << endl;
            }
           }
    }
           else {
             cout << "The database is empty" << endl;
             cout << endl;
    }
}

void PersonRepository::save() {
    ofstream outFile("PersonFile.txt");

    string tempLine;

    if(outFile.is_open()) {

        for(unsigned int i = 0; i < plist.size(); i++) {
            outFile << plist[i].name << endl;
            outFile << plist[i].gender << endl;
            outFile << plist[i].dayOfBirth << endl;
            outFile << plist[i].dayOfDeath << endl;
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

        string input, word;

        char erase;
        erase = searchFor();
        switch(erase){
            case 'n':
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, input);
            word = "name";
            eraseLoop(input, word);
            break;
        case 'g':
            cout << "Enter gender: ";
            cin.ignore();
            getline(cin, input);
            word = "gender";
            eraseLoop(input, word);
            break;
        case 'b':
            cout << "Enter year of birth: ";
            cin.ignore();
            getline(cin, input);
            word = "dayOfBirth";
            eraseLoop(input, word);
            break;
        case 'd':
            cout << "Enter year of death: ";
            cin.ignore();
            getline(cin, input);
            word = "dayOfDeath";
            eraseLoop(input, word);
            break;
        }
            }
    }

void PersonRepository::eraseLoop(string input, string word)
{

    cout << "Searching..." << endl;
    cout << endl;

    char erase;
    int index, failCounter = 0, hitCounter = 0;
    for(index = 0; index < plist.size(); index++) {
        if(input == plist[index].name) {
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
}

void PersonRepository::searchLoop(string input, string word)
{
    int index, failCounter = 0;
    for(index = 0; index < plist.size(); index++) {
       if((word == "name" && input == plist[index].name) || (word == "gender" && input == plist[index].gender) ||
               (word == "dayOfBirth" && input == plist[index].dayOfBirth)
               || (word == "dayOfDeath" && input == plist[index].dayOfDeath)){
            cout << "Found at index " << index << endl;
            cout << endl;
            cout << "Name:\t\t" << plist[index].name << endl;
            cout << "Gender:\t\t"<< plist[index].gender << endl;
            cout << "Date of birth:\t" << plist[index].dayOfBirth << endl;
            cout << "Date of death:\t" << plist[index].dayOfDeath << endl;
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
    cout << "Name:\t\t" << plist[index].name << endl;
    cout << "Gender:\t\t"<< plist[index].gender << endl;
    cout << "Date of birth:\t" << plist[index].dayOfBirth << endl;
    cout << "Date of death:\t" << plist[index].dayOfDeath << endl;
    cout << endl;

}

char PersonRepository::searchFor()
{

    char searchFor;
    cout << "enter 'n' to search for name " << endl;
    cout << "enter 'g' to search for gender " << endl;
    cout << "enter 'b' to search for birthdate " << endl;
    cout << "enter 'd' to search for deceased date " << endl;
    do{cin >> searchFor;
        if(searchFor != 'n' && searchFor != 'g' && searchFor != 'b' && searchFor != 'd')
            cout << "Invalid command! Enter 'n' 'g' 'b' or 'd'" << endl;
    }
    while(searchFor != 'n' && searchFor != 'g' && searchFor != 'b' && searchFor != 'd');
    cout << endl;

    return searchFor;
}
