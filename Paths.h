//
// Created by Nicole Vivier on 11/26/2021.
//

#ifndef INC_21F_FLIGHT_PLANNER_PATHS_H
#define INC_21F_FLIGHT_PLANNER_PATHS_H

#include "OriginalPerson.h"
#include "ContactedPerson.h"
#include "DSVector.h"


class Paths {
private:
    DSVector<pair<DSVector<pair<OriginalPerson, ContactedPerson>>, pair<double, double>>> paths;
    string startingPerson;
    string contactedPerson;
public:
    Paths();
    Paths(string, string);
    Paths(string, string, pair<DSVector<pair<OriginalPerson, ContactedPerson>>, pair<double, double>>);

    void addPath(pair<DSVector<pair<OriginalPerson, ContactedPerson>>, pair<double, double>>);

    string getStartingPerson();
    string getContactedPerson();
    DSVector<pair<DSVector<pair<OriginalPerson, ContactedPerson>>, pair<double, double>>>& getVector();
};


#endif //INC_21F_FLIGHT_PLANNER_PATHS_H
