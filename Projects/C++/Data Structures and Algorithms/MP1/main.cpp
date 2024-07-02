/*Mustafa Shah 5/7/2024**/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "miniVector.h"

using namespace std;

void storeVotes(const string filename, miniVector<string>& c, miniVector<string>& v) {
    ifstream file(filename);
    string word;
    bool candidate = 1;
    
    while (file >> word) {
        
        if (candidate) {
            c.push_back(word);
        } else {
            v.push_back(word);
        }
        
        candidate = !candidate;
    }
    
    file.close();
}

void generateFormattedFile(const string filename, miniVector<string>& c, miniVector<string>& v) {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open output file." << endl;
        return;
    }

    file << left << setw(30) << "Candidate" << setw(20) << "Votes Received" << setw(10) << "% Votes" << endl;
    file << setfill('-') << setw(60) << "-" << setfill(' ') << endl;

    int totalVotes = 0;
    for (size_t i = 1; i < v.size(); ++i) {
        totalVotes += stoi(v[i]);
    }

    for (size_t i = 1; i < c.size(); ++i) {
        double votePercentage = (stod(v[i]) / totalVotes) * 100;
        file << left << setw(30) << c[i] << setw(20) << v[i] << fixed << setprecision(1) << setw(10) << votePercentage << endl;
    }
    
    file.close();
}

int main()
{
    miniVector<string> candidates;
    miniVector<string> votes;
    
    storeVotes("votes.txt", candidates, votes);
    generateFormattedFile("votePctOutput.txt", candidates, votes);
    
    return 0;
}