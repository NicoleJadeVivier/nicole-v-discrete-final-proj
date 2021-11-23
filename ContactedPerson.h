//
// Created by Nicole Vivier on 11/22/2021.
//

#ifndef INC_21F_FLIGHT_PLANNER_CONTACTEDPERSON_H
#define INC_21F_FLIGHT_PLANNER_CONTACTEDPERSON_H
#include <string>
#include <iostream>

using namespace std;
class ContactedPerson {
private:
    string name;
public:
    ContactedPerson();
    ContactedPerson(string);

    void setName(string);
    string getName();

    friend std::ostream& operator<< (std::ostream&, const ContactedPerson&);
    bool operator== (const ContactedPerson&)const;
};


#endif //INC_21F_FLIGHT_PLANNER_CONTACTEDPERSON_H
