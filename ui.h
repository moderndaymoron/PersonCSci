#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

#include <iostream>
#include <string>
#include "PersonService.h"

class UI {
public:
    UI();

    void start();
    void getPersonInput(Person& p);
    bool isValidCommand(string input);

    void commandCenter(string input, int &saveCounter, int &editCounter);
private:
    PersonService Pservice;
};

#endif // UI_H_INCLUDED
