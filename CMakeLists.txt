cmake_minimum_required(VERSION 3.15)
project(21f_flight_planner)

set(CMAKE_CXX_STANDARD 14)

configure_file(data/sample01-paths-data.txt data/sample01-paths-data.txt COPYONLY)
configure_file(data/sample01-req-paths.txt data/sample01-req-paths.txt COPYONLY)

add_executable(21f_flight_planner main.cpp catch_setup.cpp sample_tests.cpp DSLinkedList.h DSListNode.h DSStack.h DSVector.h OriginalPerson.cpp OriginalPerson.h ContactedPerson.cpp ContactedPerson.h PathFinder.cpp PathFinder.h Paths.cpp Paths.h)
