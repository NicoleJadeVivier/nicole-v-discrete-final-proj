//
// Created by Nicole Vivier on 11/26/2021.
//

#include "Paths.h"

Paths::Paths() {
    startingPerson = "no name";
    contactedPerson = "no name";
}

Paths::Paths(string ogName, string contactedName) {
    startingPerson = ogName;
    contactedPerson = contactedName;
}
Paths::Paths(string ogName, string contactedName, pair<DSVector<pair<OriginalPerson, ContactedPerson>>, pair<double, double>> thePath) {
    startingPerson = ogName;
    contactedPerson = contactedName;
    paths.push_back(thePath);
}

DSVector<pair<DSVector<pair<OriginalPerson, ContactedPerson>>, pair<double, double>>> &Paths::getVector() {
    return paths;
}

void Paths::addPath(pair<DSVector<pair<OriginalPerson, ContactedPerson>>, pair<double, double>> thePath) {
    paths.push_back(thePath);
}
