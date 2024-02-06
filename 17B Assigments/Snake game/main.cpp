//want to make a Snake game replica to transfer to html and javascript

#include<iostream>
#include<iomanip>

using namespace std;

int main() {

    bool game = true;
    char move = 0;
    int playerX = 20, playerY = 20;

    while (game == true) {

        int tableF = 40 - playerY;

        cout << string(41, '_') << endl;
        for (int i = 0; i < 40; i++) {
            if (i == playerX) {
                cout << "|" << setw(playerY) << "o" << setw(tableF) << "|" << endl;
            } else {
                cout << "|" << setw(40) << "|" << endl;
            }
        }
        cout << string(41, '_') << endl;
        cin >> move;
        move = toupper(move);

        switch (move) {
            case 'W':
                playerX--;
                break;
            case 'A':
                playerY--;
                break;
            case 'S':
                playerX++;
                break;
            case 'D':
                playerY++;
                break;
        }

    }



}