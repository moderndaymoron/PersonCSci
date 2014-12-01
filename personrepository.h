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
    void erase();
    void search();

    double getSize();

private:
    vector<Person> plist;
};

#endif // PERSONREPOSITORY_H_INCLUDED
