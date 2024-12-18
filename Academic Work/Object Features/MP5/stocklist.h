#ifndef STOCKLIST_H
#define STOCKLIST_H

#include <vector>
#include <algorithm>
#include "stock.h"

using namespace std;

template <typename T>
class StockList {
    private:
        vector<T> stocks;

    public:
        void addStock(const T& stock);
        void sortStocks();
        void displayStocks() const;
};

// template <typename T>
// void StockList<T>::addStock(const T& stock) {
//     stocks.push_back(stock);
// }

// template <typename T>
// void StockList<T>::sortStocks() {
//     sort(stocks.begin(), stocks.end());
// }

// template <typename T>
// void StockList<T>::displayStocks() const {
//     cout << "Financial report" << endl;
//     cout << "SYM\tOPEN\tCLOSE\tHIGH\tLOW\tYesterday\tSHARES\tG/L" << endl;
//     for (const auto& stock : stocks) {
//         cout << stock << endl;
//     }
// }

#endif