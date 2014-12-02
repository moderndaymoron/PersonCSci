#include "person.h"
#include <string>

Person::Person()
{
}

string Person::getName() {
    return name;
}

void Person::setName(string s) {
    name = s;
}

string Person::getGender() {
    return gender;
}

void Person::setGender(string s) {
    gender = s;
}

string Person::getDayOfBirth() {
    return dayOfBirth;
}

void Person::setDayOfBirth(string s) {
    dayOfBirth = s;
}

string Person::getDayOfDeath() {
    return dayOfDeath;
}

void Person::setDayOfDeath(string s) {
    dayOfDeath = s;
}

bool Person::isValidPerson() {
    return true; //TODO: check for valid
}

