#ifndef SOURCE_H
#define SOURCE_H

#include <iostream>
#include <random>
#include <limits>
#include <chrono>
#include <fstream>
#include <ctime>

#ifdef _WIN32
#include <windows.h>
#elif __unix__ || __APPLE__
#include <unistd.h>
#endif

int getMode();
int getTrials();
int getOperationNumber(const std::string& filename);
void writeToFile(const std::string& filename, const std::string& content);
void montyHall(int trials);
void printDoors(int car_door, int player_choice, int opened_door);
void performance(int trials);

#endif // SOURCE_H