# Monty Hall Problem Simulator

**This C++ program simulates the famous Monty Hall problem, a probability puzzle based on a game show scenario.**

## Description

The program consists of a `main()` function and two helper functions: `printDoors()` and `montiHole()`.

In `main()`, the program simply calls the `montiHole()` function to run the simulation.

The `montiHole()` function initializes variables to keep track of the number of trials, wins by switching doors, and wins by staying with the initial choice. It then enters a loop to run a specified number of trials.

Within each trial, three doors are simulated - one with a car behind it (the prize), and the other two with goats. The player makes a random choice of a door. Then, another door with a goat behind it is revealed, which is neither the player's choice nor the one with the car.

The `printDoors()` function is called to print the state of the doors after the reveal, showing the player's initial choice and the locations of the car and goats.

After the reveal, the program simulates the player's decision to switch doors. It picks another door that wasn't the player's initial choice nor the one with the revealed goat.

The program then checks if the player's initial choice or the switched choice matches the door with the car and increments the respective win counters accordingly.

Finally, it prints out the percentage of wins by staying with the initial choice and the percentage of wins by switching doors over all trials.

The `<random>` library is used for generating random numbers. The `<windows.h>` or `<unistd.h>` header is included for a brief delay using `Sleep()` or `usleep()` function, respectively, depending on the platform, presumably for better visualization of the simulation.

## Usage

1. Compile the program using a C++ compiler.
2. Run the compiled executable.
3. Adjust the `trials` variable in the `montiHole()` function to change the number of simulation trials.

## Example Output

For the given code, the output will be similar to:

| ?? | Goat | Car | [Player's choice: Door 3] 

| Goat | ?? | Car | [Player's choice: Door 1] 

| Car | Goat | ?? | [Player's choice: Door 2] 

... 

Winning by staying with initial choice: 33.2% 

Winning by switching: 66.8%

## License

This program is released under public lisence.
