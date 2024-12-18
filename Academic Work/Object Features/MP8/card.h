#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;

class Card {
    private:
        string value, suit;
    public:
        Card();
        Card(const string& v, const string& s);
        void setValue(const string& v);
        void setSuit(const string& s);
        string getValue();
        string getSuit();
};

#endif