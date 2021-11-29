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

    //prints out adjacency list
//    pathList.set_front();
//    while(!pathList.currAtNull()) {
//        cout << pathList.get_curr_value().getOGName() << ": ";
//        pathList.get_curr_value().reset();
//        while(!pathList.get_curr_value().getContactsList().currAtNull()) {
//            cout << pathList.get_curr_value().getContactsList().get_curr_value() << " ";
//            pathList.get_curr_value().moveIter();
//        }
//        cout << endl;
//        pathList.next();
//    }
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
        //if the list is not empty, check to see if the original person already exists. If so, just append
        //the ending person to the already existing person's linkedlist.
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
        //if the object does not already exist, append the original person to the adjacency list
        pathList.append(origPerson);
        //iterate to the tail of the list because that is where the new element is
        pathList.set_front();
        while(pathList.hasNext()) {
            pathList.next();
        }
        pathList.get_curr_value().addCity(connectedPerson);
    }
}

void PathFinder::backTracking(string& ogPerson, string& contactedPerson) {
//create a new Path object
    Paths newPath(ogPerson, contactedPerson);
    //create the stack object
    DSStack<std::pair<OriginalPerson, ContactedPerson>> myStack;

    //create the pair
    std::pair<OriginalPerson, ContactedPerson> p;

    //set the iterator to the front of the Original Cities list
    pathList.set_front();

    //find the ogPerson person
    while(!pathList.currAtNull()) {
        if (pathList.get_curr_value() == ogPerson)
            break;
        else
            pathList.next();
    }

    ContactedPerson emptyPerson;
    p = std::make_pair(pathList.get_curr_value(), emptyPerson);
    //push the first person to the stack
    myStack.push(p);

    //set the iterator to the front of the contacts list
    myStack.peek().first.reset();

    while(!myStack.isEmpty()) {

        if (myStack.peek().first == contactedPerson) {
            savePaths2(myStack, newPath);
            //save stack
            //pop the top off of the stack
            myStack.pop();

            //check if the stack is empty, if so break out of the loop
            if (myStack.isEmpty())
                break;

            //is the current top of the stack at its last person?
            //pop off all elements pointing to nullptr off of the stack
            while (myStack.peek().first.getContactsList().currAtNull()) {
                myStack.pop();
                //check if the stack is empty, if so break out of the inner loop
                if (myStack.isEmpty())
                    break;
            }
            //check if the stack is empty to break out of outer loop
            if (myStack.isEmpty())
                break;

        } else {
            //is the current top pointing to nullptr?

            //iterate until it is no longer pointing to nullptr or until the stack is empty
            while (myStack.peek().first.getContactsList().currAtNull()) {
                //yes pop off the stack
                myStack.pop();
            }

            //check if the stack is empty to break out of outer loop
            if (myStack.isEmpty())
                break;

            //there are more persons to explore

            //is the next person in the list already on the stack?
            while(containsElement(myStack.peek().first.getContactsList().get_curr_value().getName(), myStack)) {
                if (myStack.peek().first.getContactsList().hasNext()) {
                    myStack.peek().first.moveIter();
                } else {
                    myStack.pop();
                    //loop makes sure that it gets to a person that is not pointing to nullptr or pops elements off
                    //the stack until it is empty or it is pointing to an element that is not pointing to nullptr
                    while (myStack.peek().first.getContactsList().currAtNull()) {
                        //yes pop off the stack
                        myStack.pop();
                        //check if the stack is empty to break out of inner loop
                        if (myStack.isEmpty())
                            break;
                    }
                }
                //check if the stack is empty to break out of the second inner loop
                if(myStack.isEmpty())
                    break;
            }

            //check if the stack is empty to break out of the outer loop
            if (myStack.isEmpty())
                break;

            //reset the flightList iterator
            pathList.set_front();

            //find original person object corresponding with the person connection
            while(!myStack.peek().first.getContactsList().currAtNull()) {
                if (myStack.peek().first.getContactsList().get_curr_value().getName() == pathList.get_curr_value().getOGName())
                    break;
                else
                    pathList.next();
            }

            p = std::make_pair(pathList.get_curr_value(), myStack.peek().first.getPerson());
            //move the iterator before pushing the next element so that it does not get stuck in an infinite loop
            myStack.peek().first.moveIter();

            //create the pair to be pushed to the stack with the original object and the corresponding connection information
            //push the next person to the stack
            myStack.push(p);

            //set the iterator to the beginning of the newly pushed person's connection list
            myStack.peek().first.reset();


        }
    }
    //push the path object which contains all the paths for the requested connection to the path stack
    pathStack.push(newPath);
}

void PathFinder::savePaths2(DSStack<std::pair<OriginalPerson, ContactedPerson>> tempStack, Paths &thePath) {
//temporary vector to hold the people
    DSVector<std::pair<OriginalPerson, ContactedPerson>> tempVec;

    //put the people in another stack to reverse them
    DSStack<std::pair<OriginalPerson, ContactedPerson>> reverseStack;

    while(!tempStack.isEmpty()) {
        reverseStack.push(tempStack.peek());
        tempStack.pop();
    }

    //add all the elements on the stack to the temporary vector
    while(!reverseStack.isEmpty()) {
        tempVec.push_back(reverseStack.peek());
        reverseStack.pop();
    }

    pair<double, double> pInfo;
    pInfo = make_pair(0.0, 0.0);

    pair<DSVector<pair<OriginalPerson, ContactedPerson>>, pair<double, double>> p;
    p = make_pair(tempVec, pInfo);

    //add the path to the path object with containing all the paths for this requested connection
    thePath.addPath(p);
}

bool PathFinder::containsElement(string currPerson, DSStack<std::pair<OriginalPerson, ContactedPerson>> tempStack) {
    while (!tempStack.isEmpty()) {
        if (currPerson == tempStack.peek().first.getOGName()) {
            return true;
        }
        tempStack.pop();
    }
    return false;
}

void PathFinder::readDesiredPaths(char *filename, char *filename2) {
    ofstream myFile(filename2);

    ifstream desiredPaths(filename);

    if(!desiredPaths.is_open()) {
        cout << "Could not open file" << endl;
    }

    string numLines;
    string startingPerson;
    string endingPerson;

    getline(desiredPaths, numLines);

    //parse the information from the file
    for (int i = 0; i < stoi(numLines); i++) {
        getline(desiredPaths, startingPerson, ' ');
        getline(desiredPaths, endingPerson);

        //find all the paths
        backTracking(startingPerson, endingPerson);

        //print the information to the file
        myFile << "All possible Covid spread paths " << i + 1 << ": ";
        myFile << pathStack.peek().getStartingPerson() << " -> " << pathStack.peek().getContactedPerson() << endl;
        //if the parameter is equal to T, call the time sorting function. Otherwise call the cost function.

        //check to see if there are any paths to print out
        if (pathStack.peek().getVector().getLength() == 0) {
            myFile << "No interactions for this requested path, no one needs to quarantine!" << endl;
        } else {
            for (int i = 0; i < pathStack.peek().getVector().getLength(); i++) {
                myFile << "   Spread Map " << i + 1 << ": " << endl;
                for (int j = 1; j < pathStack.peek().getVector().at(i).first.getLength(); j++) {
                    myFile << "      ";
                    myFile << pathStack.peek().getVector().at(i).first.at(j - 1).first;
                    myFile << " -> ";
                    myFile << pathStack.peek().getVector().at(i).first.at(j).second.getName() << endl;
                }
                myFile << endl;
            }
        }

        //pop this Paths object off of the stack to empty it for the next requested connection
        pathStack.pop();
    }

    myFile.close();
}
