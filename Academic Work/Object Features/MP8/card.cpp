#include "card.h"

Card::Card () {
    value = "";
    suit = "";
}

Card::Card(const string& v, const string& s) {
    value = v;
    suit = s;
}


void Card::setValue(const string& v) {
    value = v;
}

void Card::setSuit(const string& s) {
    suit = s;
}

string Card::getValue() {
    return value;
}

string Card::getSuit() {
    return suit;
}