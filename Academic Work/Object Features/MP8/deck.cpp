#include "deck.h"

Deck::Deck() {
    string values[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    for (const auto& suit : suits) {
        for (const auto& value : values) {
            cards.emplace_back(value, suit);
        }
    }
}

vector<Card> Deck::getCards() {
    return cards;
}

void Deck::shuffleCards() {
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(cards.begin(), cards.end());
}

void Deck::guessValue() {
    shuffleCards();
    Card selectedCard = cards.front();
    string userGuess;
    cout << "Guess the face value of the card (2-10, J, Q, K, A): ";
    cin >> userGuess;

    if (userGuess == selectedCard.getValue()) {
        cout << "Correct! The card was " << selectedCard.getValue() << " of " << selectedCard.getSuit() << ".\n";
    } else {
        cout << "Incorrect. The card was " << selectedCard.getValue() << " of " << selectedCard.getSuit() << ".\n";
    }
}

void Deck::guessSuit() {
    shuffleCards();
    Card selectedCard = cards.front();
    string userGuess;
    cout << "Guess the suit of the card (Hearts, Diamonds, Clubs, Spades): ";
    cin >> userGuess;

    if (userGuess == selectedCard.getSuit()) {
        cout << "Correct! The card was " << selectedCard.getValue() << " of " << selectedCard.getSuit() << ".\n";
    } else {
        cout << "Incorrect. The card was " << selectedCard.getValue() << " of " << selectedCard.getSuit() << ".\n";
    }
}

void Deck::guessCard() {
    shuffleCards();
    Card selectedCard = cards.front();
    string valueGuess, suitGuess;
    cout << "Guess the face value of the card (2-10, J, Q, K, A): ";
    cin >> valueGuess;
    cout << "Guess the suit of the card (Hearts, Diamonds, Clubs, Spades): ";
    cin >> suitGuess;

    if (valueGuess == selectedCard.getValue() && suitGuess == selectedCard.getSuit()) {
        cout << "Correct! The card was " << selectedCard.getValue() << " of " << selectedCard.getSuit() << ".\n";
    } else {
        cout << "Incorrect. The card was " << selectedCard.getValue() << " of " << selectedCard.getSuit() << ".\n";
    }
}
