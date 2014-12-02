#include "ui.h"
#include <stdlib.h>
#include <fstream>

UI::UI() {
    Pservice = PersonService();
}

void UI::start() {
    string input;

        cout << "Hello user." << endl;
        cout << "(Type help for command list)" << endl;


    int saveCounter = 0, editCounter = 0;

    while(true) {

        cout << ">> ";
        getline(cin, input);
        cout << endl;

        if(isValidCommand(input)) {
            commandCenter(input, saveCounter, editCounter);

        } else {
            cout << "Invalid command!" << endl;
            cout << endl;
            continue;
        }
    }
}

void UI::getPersonInput(Person& p) {
    string temp;

    cout << "Name: ";
    getline(cin, temp);
    p.setName(temp);

    cout << "Gender: ";
    getline(cin, temp);
    p.setGender(temp);

    cout << "Date of birth: ";
    getline(cin, temp);
    p.setDayOfBirth(temp);

    cout << "Date of death: ";
    getline(cin, temp);
    p.setDayOfDeath(temp);

    cout << endl;
}

bool UI::isValidCommand(string input) {
    if (input == "help" || input == "add" || input == "display" || input == "clear" || input == "save" || input == "erase" || input == "search" || input == "exit") {
        return true;
    }
    return false;
}

void UI::commandCenter(string input, int &saveCounter, int &editCounter) {
    if (input == "help") {
        Pservice.help();

    } else if (input == "add") {
        Person temp;
        getPersonInput(temp);
        if(temp.isValidPerson()) {
            Pservice.add(temp);
            editCounter++;

        } else {
            cout << "ERROR: invalid person entered!" << endl;
        }

    }else if (input == "display") {
        Pservice.display();

    } else if (input == "clear") {
        system("cls");

    } else if (input == "erase") {
        Pservice.erase();
        editCounter++;

    } else if (input == "search") {
        Pservice.search();

    } else if (input == "save") {
        Pservice.save();
        saveCounter++;
        editCounter = 0;

    }  else if (input == "exit") {
        if((editCounter != 0)) {
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

}
