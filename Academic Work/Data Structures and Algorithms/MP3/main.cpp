#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "queue.h"

using namespace std;

void openStore() {
    ofstream outfile("store_log.txt");
    if (!outfile.is_open()) {
        cerr << "Failed to open file for writing." << endl;
        return;
    }

    arrQueue<int> line;

    int currService = 0;
    int currCustomer = 0;
    int customerCount = 0;
    int nextArrival = 0;

    for (int i = 1; i <= 120; i++) {
        outfile << "Minute " << i << ": ";
        
        if (currService > 0) {
            currService--;
        }
        
        if (nextArrival == 0) {
            customerCount++;
            int serviceTime = rand() % 4 + 1;
            line.push(serviceTime);
            outfile << "Customer " << customerCount << " has entered. (Service time: " << serviceTime << " minutes)";
            if (currService == 0) {
                currService = line.front();
                line.pop();
                currCustomer++;
                outfile << " Now servicing customer " << currCustomer << ". ";
            }
            nextArrival = rand() % 4 + 1;
        } else if (currService == 0 && !line.empty()) {
            outfile << "Customer " << currCustomer << " has left. ";
            currCustomer++;
            currService = line.front();
            line.pop();
            outfile << "Now servicing customer " << currCustomer << ". ";
        } else if (currService == 0) {
            outfile << "No customers in line.";
        }
        
        outfile << "\n";
        nextArrival--;
    }

    outfile.close();
}

int main() {
    srand(time(0));
    openStore();
    
    return 0;
}
