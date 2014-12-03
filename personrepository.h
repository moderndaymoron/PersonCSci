#ifndef PERSONREPOSITORY_H_INCLUDED
#define PERSONREPOSITORY_H_INCLUDED

#include <iostream>
#include <vector>
#include <algorithm>
#include "comparer.h"
#include "person.h"

class PersonRepository {
public:
    PersonRepository();

    void add(Person p);
    void display();
    void save();

    bool isValidSearchColumn(char in);
    void searchSwitch(char searchColumn, string searchType);

    void erase();
    void eraseLoop(string input, string word);

    void search();
    void searchLoop(string input, string word);


    double getSize();

    void displayAllPersons();

private:
    vector<Person> plist;
    void displayPerson(const int index);
    char searchFor();

};

#endif // PERSONREPOSITORY_H_INCLUDED
