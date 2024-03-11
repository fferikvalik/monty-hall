#include "source.h"

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

void montiHole(){
        std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 3);

    const int trials = 10000;
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

    std::cout << "Winning by staying with initial choice: " << (double)stay_wins / trials * 100 << "%\n";
    std::cout << "Winning by switching: " << (double)switch_wins / trials * 100 << "%\n";

}