#include <iostream>
using namespace std;

#define dimension 8
char** Board = nullptr;

void initialize() {
    Board = new char* [dimension];
    for (int i = 0; i < dimension; i++) {
        Board[i] = new char [dimension];
        for (int j = 0; j < dimension; j++) {
            if (i == 0 and j == 0 || i == 0 and j == 7) Board[i][j] = 'R';
            else if (i == 0 and j == 1 || i == 0 and j == 6) Board[i][j] = 'H';
            else if (i == 0 and j == 2 || i == 0 and j == 5) Board[i][j] = 'B';
            else if (i == 7 and j == 0 || i == 7 and j == 7) Board[i][j] = 'r';
            else if (i == 7 and j == 1 || i == 7 and j == 6) Board[i][j] = 'h';
            else if (i == 7 and j == 2 || i == 7 and j == 5) Board[i][j] = 'b';
            else if (i == 1) Board[i][j] = 'P';
            else if (i == 0 and j == 3) Board[i][j] = 'K';
            else if (i == 0 and j == 4) Board[i][j] = 'Q';
            else if (i == 6) Board[i][j] = 'p';
            else if (i == 7 and j == 3) Board[i][j] = 'k';
            else if (i == 7 and j == 4) Board[i][j] = 'q';
            else Board[i][j] = '.';
        }
    }
}

char givePiece(int row, int col) {
    return Board[row][col];
}


void printBoard() {
    cout << endl;
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++)
            cout << Board[i][j] << ' ';
        cout << endl;
    }

}

int main() {
    initialize();
    printBoard();
}