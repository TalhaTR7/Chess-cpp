#include <iostream>
using namespace std;

#define dimension 8
enum class player { WHITE, BLACK };
player turn = player::WHITE;
char** Board = nullptr;

void initialize() {
    Board = new char* [dimension];
    for (int i = 0; i < dimension; i++) {
        Board[i] = new char [dimension];
        for (int j = 0; j < dimension; j++) {
            if (i == 0 and j == 0 or i == 0 and j == 7) Board[i][j] = 'R';
            else if (i == 0 and j == 1 or i == 0 and j == 6) Board[i][j] = 'H';
            else if (i == 0 and j == 2 or i == 0 and j == 5) Board[i][j] = 'B';
            else if (i == 7 and j == 0 or i == 7 and j == 7) Board[i][j] = 'r';
            else if (i == 7 and j == 1 or i == 7 and j == 6) Board[i][j] = 'h';
            else if (i == 7 and j == 2 or i == 7 and j == 5) Board[i][j] = 'b';
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


void switchTurn() {
    if (turn == player::BLACK) turn = player::WHITE;
    else turn = player::BLACK;
}

void printBoard() {
    cout << endl;
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++)
            cout << Board[i][j] << ' ';
        cout << endl;
    }
}

bool verifyBox(char boxRow, int boxCol) {
    if (toupper(boxRow) >= 'A' and toupper(boxRow) <= 'H')
        if (boxCol >= 1  and boxCol <= 8)
            return true;
    return false;
}

bool isValidBox(int row, int col) {
    if (turn == player::WHITE) {
        return (givePiece(row, col) == 'R' or
            givePiece(row, col) == 'H' or
            givePiece(row, col) == 'B' or
            givePiece(row, col) == 'K' or
            givePiece(row, col) == 'Q' or
            givePiece(row, col) == 'P')
            ? true : false;
    }
    else if (turn == player::BLACK) {
        return (givePiece(row, col) == 'r' or
            givePiece(row, col) == 'h' or
            givePiece(row, col) == 'b' or
            givePiece(row, col) == 'k' or
            givePiece(row, col) == 'q' or
            givePiece(row, col) == 'p')
            ? true : false;
    }
    return false;
}

void makeMove() {
}

int main() {
    char row;
    int col;
    cout << "enter: ";
    cin >> row >> col;
    cout << verifyBox(row, col);
}