#include <iostream>

using namespace std;

class Race {
    public:
        int tPos, hPos;
        Race();
        void printPositions();
};

// Race::Race() {
//     tPos = 1;
//     hPos = 1;
// }

// void Race::printPositions () {
//     for (int i = 1; i <= 50; i++) {
//         if (i == tPos && i == hPos) {
//             cout << "O";
//         } else if (i == tPos) {
//             cout << "T";
//         } else if (i == hPos) {
//             cout << "H";
//         } else {
//             cout << "*";
//         }
//     }
//     cout << "\n";
// }
