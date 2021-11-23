//
// Created by Nicole Vivier on 11/22/2021.
//

#include "ContactedPerson.h"

ContactedPerson::ContactedPerson() {
    name = " ";
}

ContactedPerson::ContactedPerson(string theName) {
    name = theName;
}

void ContactedPerson::setName(string theName) {
    name = theName;
}

string ContactedPerson::getName() {
    return name;
}

std::ostream &operator<<(ostream &os, const ContactedPerson &thePerson) {
     os << thePerson.name;
     return os;
}

bool ContactedPerson::operator==(const ContactedPerson &thePerson) const {
    if (name == thePerson.name)
        return true;
}
