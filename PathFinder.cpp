//
// Created by Nicole Vivier on 11/22/2021.
//

#include "PathFinder.h"

void PathFinder::readFile(char *filename) {
    ifstream pathDetails(filename);

    if (!pathDetails.is_open()) {
        cout << "Unable to open the file" << endl;
    }

    string numLines;
    string line;
    getline(pathDetails, numLines);

    for (int i = 0; i < stoi(numLines); i++) {
        getline(pathDetails, line);
        parseFile(line);
    }

    pathList.set_front();
    while(!pathList.currAtNull()) {
        cout << pathList.get_curr_value().getOGName() << ": ";
        pathList.get_curr_value().reset();
        while(!pathList.get_curr_value().getContactsList().currAtNull()) {
            cout << pathList.get_curr_value().getContactsList().get_curr_value() << " ";
            pathList.get_curr_value().moveIter();
        }
        cout << endl;
        pathList.next();
    }
}

void PathFinder::parseFile(string str) {
    stringstream ss(str);

    string originalPerson;
    string contactedPerson;

    getline(ss, originalPerson, ' ');
    getline(ss, contactedPerson);

    OriginalPerson rootPerson(originalPerson);
    ContactedPerson branchPerson(contactedPerson);

    //add to adjacency list
    appendPerson(rootPerson, branchPerson);

    OriginalPerson rootPerson_reverse(contactedPerson);
    ContactedPerson branchPerson_reverse(originalPerson);

    //add to adjacency list
    appendPerson(rootPerson_reverse, branchPerson_reverse);
}

void PathFinder::appendPerson(OriginalPerson origPerson, ContactedPerson connectedPerson) {
//if the list is empty, add the new element to become the first element
    if (pathList.isEmpty()) {
        pathList.append(origPerson);
        pathList.set_front();
        //add the destination city to that original city's linkedlist.
        pathList.get_curr_value().addCity(connectedPerson);
    } else {
        //if the list is not empty, check to see if the original city already exists. If so, just append
        //the destination city to the already existing city's linkedlist.
        pathList.set_front();
        while (pathList.hasNext()) {
            if (origPerson == pathList.get_curr_value()) {
                pathList.get_curr_value().addCity(connectedPerson);
                return;
            }
            pathList.next();
        }
        if (origPerson == pathList.get_curr_value()) {
            pathList.get_curr_value().addCity(connectedPerson);
            return;
        }
        //if the object does not already exist, append the originalCity to the adjacency list
        pathList.append(origPerson);
        //iterate to the tail of the list because that is where the new element is
        pathList.set_front();
        while(pathList.hasNext()) {
            pathList.next();
        }
        pathList.get_curr_value().addCity(connectedPerson);
    }
}
