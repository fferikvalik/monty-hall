#include "source.h"

int main() {
    int mode = getMode();
    int trials = getTrials();

    switch(mode) {
        case 1:
            montyHall(trials);
            break;
        case 2:
            performance(trials);
            break;
    }

    return 0;
}