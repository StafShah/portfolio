#include "stock.h"
#include <iostream>
#include <iomanip>

using namespace std;

Stock::Stock() 
    :symbol(""), openPrice(0.0), closePrice(0.0), highPrice(0.0), lowPrice(0.0), prevPrice(0.0), percentGainOrLoss(0.0), numOfShares(0) {}

Stock::Stock(const string& s, double op, double cp, double hp, double lp, double pp, int ns)
    :symbol(s), openPrice(op), closePrice(cp), highPrice(hp), lowPrice(lp), prevPrice(pp), percentGainOrLoss(0.0), numOfShares(ns) {}

void Stock::setSymbol(const string& s) {
    symbol = s;
}

void Stock::setOpenPrice(double op) {
    openPrice = op;
}

void Stock::setClosePrice(double cp) {
    closePrice = cp;
}

void Stock::setHighPrice(double hp) {
    highPrice = hp;
}

void Stock::setLowPrice(double lp) {
    lowPrice = lp;
}

void Stock::setPrevPrice(double pp) {
    prevPrice = pp;
}

void Stock::setNumOfShares(int ns) {
    numOfShares = ns;
}

void Stock::displayOpen() const {
    cout << "Open Price: " << openPrice << endl;
}

void Stock::displayClose() const {
    cout << "Close Price: " << closePrice << endl;
}

void Stock::displayHigh() const {
    cout << "High Price: " << highPrice << endl;
}

void Stock::displayLow() const {
    cout << "Low Price: " << lowPrice << endl;
}

void Stock::displayPrev() const {
    cout << "Previous Price: " << prevPrice << endl;
}

void Stock::calculateGL() {
    percentGainOrLoss = ((closePrice - prevPrice) / prevPrice) * 100;
    cout << "Percent Gain/Loss: " << fixed << setprecision(2) << percentGainOrLoss << "%" << endl;
}

bool Stock::operator<(const Stock& other) const {
    return symbol < other.symbol;
}

bool Stock::operator>(const Stock& other) const {
    return symbol > other.symbol;
}

bool Stock::operator==(const Stock& other) const {
    return symbol == other.symbol;
}

ostream& operator<<(ostream& os, const Stock& stock) {
    os << stock.symbol << " " << stock.openPrice << " " << stock.closePrice << " "
       << stock.highPrice << " " << stock.lowPrice << " " << stock.prevPrice << " "
       << stock.numOfShares << " " << fixed << setprecision(2) << stock.percentGainOrLoss << "%";
    return os;
}

istream& operator>>(istream& is, Stock& stock) {
    is >> stock.symbol >> stock.openPrice >> stock.closePrice >> stock.highPrice >> stock.lowPrice 
       >> stock.prevPrice >> stock.numOfShares;
    stock.calculateGL();
    return is;
}