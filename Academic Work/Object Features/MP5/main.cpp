/*Mustafa Shah*/
#include <iostream>
#include <fstream>
#include "stock.h"
#include "stocklist.h"

using namespace std;


int main() {
    StockList<Stock> stockList;
    ifstream inputFile("input.txt");
    Stock stock;
    while (inputFile >> stock) {
        stockList.addStock(stock);
    }

    inputFile.close();

    stockList.sortStocks();
    stockList.displayStocks();

    return 0;
}