#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "card.h"

using namespace std;

class Deck {
    private:
        vector<Card> cards;
    public:
        Deck();
        vector<Card> getCards();
        void shuffleCards();
        void guessValue();
        void guessSuit();
        void guessCard();
};

#endif