#include "PersonRepository.h"
#include <fstream>
#include <string>
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
            temp.name = line1;
            temp.gender = line2;
            temp.dayOfBirth = line3;
            temp.dayOfDeath = line4;
            plist.push_back(temp);
        }

    } else {
        cout << "ERROR: cannot open file." << endl;

    }

    inFile.close();
}

void PersonRepository::add(Person p) {
    plist.push_back(p);

}

void PersonRepository::display() {
    if(plist.size()) {

        for(unsigned int i = 0; i < plist.size(); i++) {
            cout << "Name: " << plist[i].name << endl;
            cout << "Gender: "<< plist[i].gender << endl;
            cout << "Date of birth: " << plist[i].dayOfBirth << endl;
            cout << "Date of death: " << plist[i].dayOfDeath << endl;
            cout << endl;
        }

    } else {
        cout << "The database is empty" << endl;
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

    } else {
        cout << "ERROR: cannot open file." << endl;
    }

    outFile.close();
}

double PersonRepository::getSize() {
    return plist.size();
}
