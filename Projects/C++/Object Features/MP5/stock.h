#ifndef STOCK_H
#define STOCK_H

#include <iostream>

using namespace std;

class Stock {
    private:
        string symbol;
        double openPrice, closePrice, highPrice, lowPrice, prevPrice, percentGainOrLoss;
        int numOfShares;
        
    public:
        Stock();
        Stock(const string& s, double op, double cp, double hp, double lp, double pp, int ns);
        void setSymbol(const string& s);
        void setOpenPrice(double op);
        void setClosePrice(double cp);
        void setHighPrice(double hp);
        void setLowPrice(double lp);
        void setPrevPrice(double pp);
        void setNumOfShares(int ns);
        void displayOpen() const;
        void displayClose() const;
        void displayHigh() const;
        void displayLow() const;
        void displayPrev() const;
        void calculateGL();
        bool operator<(const Stock& other) const;
        bool operator>(const Stock& other) const;
        bool operator==(const Stock& other) const;
        friend ostream& operator<<(ostream& os, const Stock& stock);
        friend istream& operator>>(istream& is, Stock& stock);
};

#endif