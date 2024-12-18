#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Board {
private:
    vector<vector<char>> board;

public:
    Board();
    vector<vector<char>> getBoard();
    void displayBoard();
    bool insert(const char& piece);
    bool checkWin();
    bool checkDraw();
    bool checkHorizontal(const char& piece);
    bool checkVertical(const char& piece);
    bool checkDiagonal(const char& piece);
    bool checkDirection(int row, int col, int dRow, int dCol, const char& piece, int count);
    void beginGame();
};

Board::Board() {
    board = vector<vector<char>>(6, vector<char>(7, '*'));
}

vector<vector<char>> Board::getBoard() {
    return board;
}

void Board::displayBoard() {
    for (int row = 0; row < 6; ++row) {
        for (int col = 0; col < 7; ++col) {
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool Board::insert(const char& piece) {
    int col;
    cout << "Drop a " << piece << " disc at column (0–6): ";
    cin >> col;
    for (int row = 5; row >= 0; --row) {
        if (row == 0 && board[row][col] != '*') {
            cout << "Column is full, try again!" << endl;
            return insert(piece);
        }
        if (board[row][col] == '*') {
            board[row][col] = piece;
            return true;
        }
    }
    return true;
}

bool Board::checkWin() {
    return checkHorizontal('R') || checkHorizontal('Y') ||
           checkVertical('R') || checkVertical('Y') ||
           checkDiagonal('R') || checkDiagonal('Y');
}

bool Board::checkDraw() {
    for (int col = 0; col < 7; ++col) {
        if (board[0][col] == '*') {
            return false;
        }
    }
    return true;
}

bool Board::checkHorizontal(const char& piece) {
    for (int row = 0; row < 6; ++row) {
        for (int col = 0; col < 4; ++col) {
            if (checkDirection(row, col, 0, 1, piece, 4)) {
                return true;
            }
        }
    }
    return false;
}

bool Board::checkVertical(const char& piece) {
    for (int col = 0; col < 7; ++col) {
        for (int row = 0; row < 3; ++row) {
            if (checkDirection(row, col, 1, 0, piece, 4)) {
                return true;
            }
        }
    }
    return false;
}

bool Board::checkDiagonal(const char& piece) {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 4; ++col) {
            if (checkDirection(row, col, 1, 1, piece, 4) || 
                checkDirection(row, col + 3, 1, -1, piece, 4)) {
                return true;
            }
        }
    }
    return false;
}

bool Board::checkDirection(int row, int col, int dRow, int dCol, const char& piece, int count) {
    if (count == 0) {
        return true;
    }
    if (row < 0 || row >= 6 || col < 0 || col >= 7 || board[row][col] != piece) {
        return false;
    }
    return checkDirection(row + dRow, col + dCol, dRow, dCol, piece, count - 1);
}

void Board::beginGame() {
    char currentPlayer = 'R';
    while (true) {
        displayBoard();
        insert(currentPlayer);
        if (checkWin()) {
            displayBoard();
            cout << "The " << (currentPlayer == 'R' ? "red" : "yellow") << " player won. Congratulations." << endl;
            break;
        }
        if (checkDraw()) {
            displayBoard();
            cout << "The game is a draw." << endl;
            break;
        }
        currentPlayer = (currentPlayer == 'R' ? 'Y' : 'R');
    }
}
