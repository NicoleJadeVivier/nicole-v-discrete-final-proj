//
// Created by Nicole Vivier on 11/22/2021.
//

#include "OriginalPerson.h"

OriginalPerson::OriginalPerson() {
    name = " ";
}

OriginalPerson::OriginalPerson(string theName) {
    name = theName;
}

OriginalPerson::OriginalPerson(string theName, ContactedPerson person) {
    name = theName;
    contactsList.append(person);
}

bool OriginalPerson::operator==(const OriginalPerson &person) const {
    if (name == person.name)
        return true;
    else
        return false;
}

string OriginalPerson::getOGName() {
    return name;
}

std::ostream &operator<<(ostream &os, const OriginalPerson &person) {
    os << person.name;
    return os;
}

void OriginalPerson::addCity(ContactedPerson person) {
    contactsList.append(person);
}

void OriginalPerson::printInfo() {
    cout << "Original Person: " << name << endl;
    cout << "Contacts: " << endl;
    contactsList.set_front();
    while (!contactsList.currAtNull()) {
        cout << "\t" << contactsList.get_curr_value();
        contactsList.next();
    }
}

void OriginalPerson::printContacts() {
    contactsList.print();
}

void OriginalPerson::reset() {
    contactsList.set_front();
}

void OriginalPerson::moveIter() {
    if (!contactsList.currAtNull()) {
        contactsList.next();
    } else
        throw std::runtime_error("OriginalPerson moveIter(): already at nullptr");
}

ContactedPerson &OriginalPerson::getPerson() {
    if (!contactsList.currAtNull())
        return contactsList.get_curr_value();
    else
        throw std::runtime_error("Original Person getPerson(): cannot return nullptr");
}

DSLinkedList<ContactedPerson> &OriginalPerson::getContactsList() {
    return contactsList;
}


