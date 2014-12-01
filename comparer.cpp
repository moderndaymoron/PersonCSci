#include "comparer.h"

Comparer::Comparer() {
    order = "";
}

Comparer::Comparer(string ord) {
    order = ord;
}

bool Comparer::operator ()(const Person first, const Person second) {
    if(order == "name") {
        return first.name < second.name;
    } else if(order == "gender") {
        return first.gender < second.gender;
    } else if(order == "date of birth") {
        return first.dayOfBirth < second.dayOfBirth;
    } else if(order == "date of death") {
        return first.dayOfDeath < second.dayOfDeath;
    }
    throw;
}
