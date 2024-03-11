#include "source.h"

int operationNumber = 0;

int getMode() {
    int mode;
    do {
        std::cout << "Choose mode: 1 - visual, 2 - performance: ";
        while(!(std::cin >> mode) || (mode != 1 && mode != 2)) {
            std::cout << "Invalid mode selection. Please try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (mode != 1 && mode != 2);
    return mode;
}

int getTrials() {
    int trials;
    do {
        std::cout << "Enter the number of iterations: ";
        while(!(std::cin >> trials) || trials <= 0) {
            std::cout << "The number of iterations must be greater than 0. Please try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (trials <= 0);
    return trials;
}

void printDoors(int car_door, int player_choice, int opened_door) {
    for (int i = 1; i <= 3; ++i) {
        std::cout << "| ";
        if (i == car_door) {
            std::cout << (i == opened_door ? "Goat " : "Car  ");
        } else {
            std::cout << (i == opened_door ? "Goat " : "??   ");
        }
        std::cout << "| ";
    }
    std::cout << "  [Player's choice: Door " << player_choice << "]\n";
}

int getOperationNumber(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        int count = 0;
        std::string line;
        while (std::getline(file, line)) {
            count++;
        }
        file.close();
        return count + 1; // Теперь каждая операция занимает только одну строку
    } else {
        return 1; // Если файл не открыт, это первая операция
    }
}

void writeToFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename, std::ios::app); // Открываем файл в режиме добавления
    if (file.is_open()) {
        file << content << "\n";
        file.close();
    } else {
        std::cout << "Unable to open file";
    }
}

#include <algorithm> // Include the <algorithm> header to use std::remove

std::string formatTime(std::time_t time) {
    std::string timeStr = std::ctime(&time);
    timeStr.erase(std::remove(timeStr.begin(), timeStr.end(), '\n'), timeStr.end()); // Remove the newline character correctly
    return timeStr;
}


void montyHall(int trials) {
    int operationNumber = getOperationNumber("results/results.txt");
    auto start = std::chrono::high_resolution_clock::now();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 3);

    int switch_wins = 0;
    int stay_wins = 0;

    for (int i = 0; i < trials; ++i) {
        int car_door = dis(gen);
        int player_choice = dis(gen);

        int opened_door;
        do {
            opened_door = dis(gen);
        } while (opened_door == car_door || opened_door == player_choice);

        printDoors(car_door, player_choice, opened_door);

        int switch_choice = dis(gen);
        while (switch_choice == player_choice || switch_choice == opened_door) {
            switch_choice = dis(gen);
        }

        stay_wins += (player_choice == car_door);
        switch_wins += (switch_choice == car_door);
    }

    double stay_percentage = (double)stay_wins / trials * 100;
    double switch_percentage = (double)switch_wins / trials * 100;

    std::cout << "Winning by staying with initial choice: " << stay_percentage << "%\n";
    std::cout << "Winning by switching: " << switch_percentage << "%\n";

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    auto s = elapsed.count() / 1000;
    auto ms = elapsed.count() % 1000;
    std::time_t currentTime = std::time(nullptr);
    std::string result = "Operation " + std::to_string(operationNumber) + ", Start time: [" + formatTime(currentTime) + "], Elapsed time: (" + std::to_string(s) + " seconds " + std::to_string(ms) + " milliseconds), Trials: <" + std::to_string(trials) + ">, Mode: {Visual}, Winning by staying: " + std::to_string(stay_percentage) + "%, Winning by switching: " + std::to_string(switch_percentage) + "%";
    std::cout << result << "\n";
    writeToFile("results/results.txt", result);
}

void performance(int trials) {
    int operationNumber = getOperationNumber("results/results.txt");
    auto start = std::chrono::high_resolution_clock::now();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 3);

    int switch_wins = 0;
    int stay_wins = 0;

    for (int i = 0; i < trials; ++i) {
        int car_door = dis(gen);
        int player_choice = dis(gen);

        int opened_door;
        do {
            opened_door = dis(gen);
        } while (opened_door == car_door || opened_door == player_choice);

        int switch_choice = dis(gen);
        while (switch_choice == player_choice || switch_choice == opened_door) {
            switch_choice = dis(gen);
        }

        stay_wins += (player_choice == car_door);
        switch_wins += (switch_choice == car_door);
    }

    double stay_percentage = (double)stay_wins / trials * 100;
    double switch_percentage = (double)switch_wins / trials * 100;

    std::cout << "Winning by staying with initial choice: " << stay_percentage << "%\n";
    std::cout << "Winning by switching: " << switch_percentage << "%\n";

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    auto s = elapsed.count() / 1000;
    auto ms = elapsed.count() % 1000;
    std::time_t currentTime = std::time(nullptr);
    std::string result = "Operation " + std::to_string(operationNumber) + ", Start time: [" + formatTime(currentTime) + "], Elapsed time: (" + std::to_string(s) + " seconds " + std::to_string(ms) + " milliseconds), Trials: <" + std::to_string(trials) + ">, Mode: {Performance}, Winning by staying: " + std::to_string(stay_percentage) + "%, Winning by switching: " + std::to_string(switch_percentage) + "%";
    std::cout << result << "\n";
    writeToFile("results/results.txt", result);
}