#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class card
{
private:

    int cardID;
    int value;
    char suit;

public:

    card(int a = 0, int b = 0, char c = 0)
        :cardID(a), value(b), suit(c) {}

    friend ostream& operator<< (ostream& out, card& myCard) {
        string V;
        char S;
        if (myCard.value == 1) V = "A";
        else if (myCard.value == 11) V = "J";
        else if (myCard.value == 12) V = "Q";
        else if (myCard.value == 13) V = "K";
        else V = to_string(myCard.value);

        if (myCard.suit == 'H') S = char(3);
        else if (myCard.suit == 'D') S = char(4);
        else if (myCard.suit == 'C') S = char(5);
        else S = char(6);

        out << V << S;
        return out;
    }
};


card* deck = nullptr;

void fillDeck() {
    int cardID = 0;
    deck = new card[52];
    for (int i = 0; i < 52; i++) {
        if (i / 13 == 0) deck[i] = card(cardID++, (i % 13) + 1, 'D');
        else if (i / 13 == 1) deck[i] = card(cardID++, (i % 13) + 1, 'C');
        else if (i / 13 == 2) deck[i] = card(cardID++, (i % 13) + 1, 'H');
        else deck[i] = card(cardID++, (i % 13) + 1, 'S');
    }
}


int main() {
    fillDeck();
    for (int i = 0; i < 52; i++) {
        if (i % 13 == 0) cout << endl;
        cout << deck[i] << ' ';
    }
}