#ifndef PERSONREPOSITORY_H_INCLUDED
#define PERSONREPOSITORY_H_INCLUDED

#include <iostream>
#include <vector>
#include "person.h"

class PersonRepository {
public:
    PersonRepository();

    void add(Person p);
    void display();
    void save();
    void erase();
    void search();
    void searchLoop(string input, string word);

    double getSize();

private:
    vector<Person> plist;

};

#endif // PERSONREPOSITORY_H_INCLUDED
