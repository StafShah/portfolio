/*Mustafa Shah*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "race.h"

using namespace std;

const int raceEnd = 50;

void moveTortoise (int* position) {
    int time = 0;
    
    while (time <= 100) {
        int n = rand() % 10 + 1;
        if (n >= 1 && n <= 5) {
            *position = min(50, *position + 3);
            time += 50;
        } else if (n >= 6 && n <= 7) {
            *position = max(0, *position - 6);
            time += 20;
        } else {
            *position = min(50, *position + 1);
            time += 30;
        }
    }
}

void moveHare (int* position) {
    int time = 0;
    
    while (time <= 100) {
        int n = rand() % 10 + 1;
        if (n >= 1 && n <= 2) {
            time += 20;
        } else if (n >= 3 && n <= 4) {
            *position = min(50, *position + 9);
            time += 20;
        } else if (n >= 5 && n <= 6) {
            *position = max(0, *position - 12);
            time += 10;
        } else if (n >= 7 && n <= 8) {
            *position = min(50, *position + 1);
            time += 30;
        } else {
            *position = max(0, *position - 2);
            time += 20;
        }
    }
}

void runRace (Race r) {
    while (r.tPos < raceEnd && r.hPos < raceEnd) {
        moveTortoise(&r.tPos);
        moveHare(&r.hPos);
        r.printPositions();
    }
    
    if (r.tPos == raceEnd && r.hPos == raceEnd) {
        cout << "It's a tie!";
    } else if (r.tPos == raceEnd) {
        cout << "Tortoise wins!";
    } else if (r.hPos == raceEnd) {
        cout << "Hare wins!";
    } else {
        cout << "No winner.";
    }
}

int main()
{
    srand(time(0));
    Race r;
    runRace(r);
    return 0;
}