#ifndef SOURCE_H
#define SOURCE_H

#include <iostream>
#include <random>


#ifdef _WIN32
#include <windows.h>
#elif __unix__ || __APPLE__
#include <unistd.h>
#endif
void montiHole();
void printDoors(int car_door, int player_choice, int opened_door);

#endif // SOURCE_H