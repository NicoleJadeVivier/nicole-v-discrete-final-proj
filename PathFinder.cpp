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
        cout << line << endl;
    }
}
