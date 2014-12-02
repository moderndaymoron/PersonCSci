#ifndef PERSONSERVICE_H_INCLUDED
#define PERSONSERVICE_H_INCLUDED

#include <iostream>
#include "PersonRepository.h"

class PersonService {
public:
    PersonService();

    void add(Person p);
    void display();
    void save();
    void erase();
    void search();
    void help();

    double getSize();

private:
    PersonRepository pRepo;

};

#endif // PERSONSERVICE_H_INCLUDED
