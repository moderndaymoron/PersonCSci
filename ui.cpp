#include "ui.h"
#include <stdlib.h>

UI::UI() {
    Pservice = PersonService();
}

void UI::start() {
    Person temp;
    string input;
    cout << "Hello user." << endl;
    cout << "(Type help for command list)" << endl;

    double oldSize = Pservice.getSize();
    int saveCounter = 0;

    while(true) {
        cout << ">> ";
        getline(cin, input);
        cout << endl;

        if(isValidCommand(input)) {
            if (input == "help") {
                cout << "Available commands: help, add, display, clear, search, erase, save, exit." << endl;
                cout << endl;

            } else if (input == "add") {
                getPersonInput(temp);
                Pservice.add(temp);

            }else if (input == "display") {
                Pservice.display();

            } else if (input == "clear") {
                system("cls");

            } else if (input == "erase") {
                Pservice.erase();

            } else if (input == "search") {
                Pservice.search();

            } else if (input == "save") {
                Pservice.save();
                saveCounter++;

            }  else if (input == "exit") {
                if((Pservice.getSize() != oldSize) && !(saveCounter)) {
                    char answer;
                    cout << "You have unsaved changes, would you like to save (y/n)? ";
                    cin >> answer;

                    if(answer == 'y' || answer == 'Y') {
                        Pservice.save();
                    }
                }

                cout << "Thanks for using our database program!" << endl;
                cout << endl;
                exit(0);
            }

        } else {
            cout << "Invalid command!" << endl;
            cout << endl;
            continue;
        }
    }
}

void UI::getPersonInput(Person& p) {
    cout << "Name: ";
    getline(cin, p.name);
    cout << "Gender: ";
    getline(cin, p.gender);
    cout << "Date of birth: ";
    getline(cin, p.dayOfBirth);
    cout << "Date of death: ";
    getline(cin, p.dayOfDeath);
    cout << endl;
}

bool UI::isValidCommand(string input) {
    if (input == "help" || input == "add" || input == "display" || input == "clear" || input == "save" || input == "erase" || input == "search" || input == "exit") {
        return true;
    }
    return false;
}
