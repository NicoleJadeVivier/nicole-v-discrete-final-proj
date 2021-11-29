/**
 * Fall 2021 PA 04 - Flight Planner Template Repo.
 * Based on PA 02 Template repo
 */

//Nicole Vivier
//CS2353
//Rachel Becker
//12/6/21

//Project based off of CS2341 PA04
#include <iostream>
#include <fstream>

/**
 * catch_setup.h and catch_setup.cpp contain the #define directive for
 * the CATCH2 framework.  You can see in main below how I'm calling the
 * runCatchTests() function which is declared in this header.
 *
 * On average, this should reduce the build time for your project on your local
 * machine.
 */
#include "catch_setup.h"
#include "PathFinder.h"

int main(int argc, char** argv) {
    if(argc == 1) {
        runCatchTests();
    }
    else {
        PathFinder myPathFinder;
        myPathFinder.readFile(argv[1]);
        myPathFinder.readDesiredPaths(argv[2], argv[3]);
    }
    return 0;
}