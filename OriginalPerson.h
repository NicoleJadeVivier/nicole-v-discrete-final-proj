//
// Created by Nicole Vivier on 11/22/2021.
//

#ifndef INC_21F_FLIGHT_PLANNER_ORIGINALPERSON_H
#define INC_21F_FLIGHT_PLANNER_ORIGINALPERSON_H
#include "ContactedPerson.h"
#include "DSLinkedList.h"

class OriginalPerson {
private:
    string name;
    DSLinkedList<ContactedPerson> contactsList;
public:
    OriginalPerson();
    OriginalPerson(string);
    OriginalPerson(string, ContactedPerson);

    bool operator== (const OriginalPerson&)const;
    string getOGName();

    friend std::ostream& operator<< (std::ostream&, const OriginalPerson&);

    void addCity(ContactedPerson);
    void printInfo();
    void printContacts();

    //iterator wrapper functions to make it easier to implement in PathFinder
    void reset();
    void moveIter();
    ContactedPerson& getPerson();
    DSLinkedList<ContactedPerson>& getContactsList();

};


#endif //INC_21F_FLIGHT_PLANNER_ORIGINALPERSON_H
