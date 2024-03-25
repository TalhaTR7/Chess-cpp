#include <iostream>
using namespace std;

#define dimension 8
char** Board;

struct position {
    int row, col;
    position (int x = 0, int y = 0)
        :row(x),  col(y) {}
};


void initialize() {
    Board = new char* [dimension];
    for (int i = 0; i < dimension; i++) {
        Board[i] = new char [dimension];
        for (int y = 0; y < dimension; y++) {
            Board[i][y] = '.';
        }
    }
}

void printBoard() {
    char label1 = 'A', label2 = 'H';
    cout << "   1 2 3 4 5 6 7 8" << endl << endl;
    for (int i = 0; i < dimension; i++) {
        cout << label1++ << ' ' << ' ';
        for (int j = 0; j < dimension; j++) {
            cout << Board[i][j] << ' ';
        }
        cout << ' ' << label2-- << endl;
    }
    cout << endl << "   8 7 6 5 4 3 2 1" << endl;
}

int main() {
    
    // Initialize the board.
    initialize();
    
    // Print initial state of the board.
    printBoard();
}