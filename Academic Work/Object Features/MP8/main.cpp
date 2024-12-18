/*Mustafa Shah*/
#include <iostream>
#include <fstream>
#include "deck.h"

using namespace std;


void playGame() {
    Deck deck;
    int choice;
    ofstream outFile("output.txt");

    do {
        cout << "Card Guessing Game Menu:\n";
        cout << "1. Guess only the face value of the card\n";
        cout << "2. Guess only the suit of the card\n";
        cout << "3. Guess both the face value and the suit of the card\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Guessing only the face value.\n";
                deck.guessValue();
                break;
            case 2:
                cout << "Guessing only the suit.\n";
                deck.guessSuit();
                break;
            case 3:
                cout << "Guessing both the face value and the suit.\n";
                deck.guessCard();
                break;
            case 4:
                cout << "Exiting the game.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

        // Append the output to the file
        outFile << "Choice: " << choice << endl;
        switch (choice) {
            case 1:
                deck.guessValue();
                break;
            case 2:
                deck.guessSuit();
                break;
            case 3:
                deck.guessCard();
                break;
            case 4:
                break;
            default:
                break;
        }
    } while (choice != 4);

    outFile.close();
}

int main()
{
    playGame();
    return 0;
}