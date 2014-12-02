#include "PersonService.h"

PersonService::PersonService() {
    pRepo = PersonRepository();
}

void PersonService::add(Person p) {
    pRepo.add(p);
}

void PersonService::display() {
    pRepo.display();
}

void PersonService::save() {
    pRepo.save();
}

void PersonService::erase() {
    pRepo.erase();
}

void PersonService::search() {
    pRepo.search();
}

double PersonService::getSize() {
    return pRepo.getSize();
}

void PersonService::help(){
    cout << "Available commands:\n";
    cout << endl;
    cout << "help\t (get list of commands)\n";
    cout << "add\t (add to repository)\n";
    cout << "display\t (displays repository (optionally sorted))\n";
    cout << "clear\t (clears display)\n";
    cout << "search\t (search in repository)\n";
    cout << "erase\t (erase from repository)\n";
    cout << "save\t (save changes)\n";
    cout << "exit\t (quit)\n";
    cout << endl;
    cout << "Interaction:\n";
    cout << ">>\t (waiting for command)\n";
    cout << endl;
}
