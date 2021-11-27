//
// Created by Nicole Vivier on 11/22/2021.
//

#ifndef INC_21F_FLIGHT_PLANNER_PATHFINDER_H
#define INC_21F_FLIGHT_PLANNER_PATHFINDER_H
#include <fstream>
#include <sstream>

#include "ContactedPerson.h"
#include "OriginalPerson.h"
#include "DSLinkedList.h"
#include "DSVector.h"
#include "DSStack.h"


class PathFinder {
private:
    DSLinkedList<OriginalPerson> pathList;
public:
    void readFile(char*);
    void parseFile(string);
    void appendPerson(OriginalPerson, ContactedPerson);

    void backTracking(string&, string&);

};


#endif //INC_21F_FLIGHT_PLANNER_PATHFINDER_H
