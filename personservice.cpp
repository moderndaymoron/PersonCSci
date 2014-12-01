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
