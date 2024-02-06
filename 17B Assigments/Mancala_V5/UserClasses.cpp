#include <iostream>  //I/O Library
using namespace std;
#include"USER.h"
#include"PlayerInfo.h"
#include"UserInfo.h"
#include "ADMIN.h"//for line #106

//User Libraries
#include<iomanip>
#include <cstring>
#include <fstream>


void User::Play(Player &p1, Player &p2, int board[]) {


    int c = 0;
    bool cont = true;
    setBoard(board);
    dBrd(board, p1, p2);
    p1.min = 0;
    p1.max = 5;
    p2.min = 6;
    p2.max = 11;

    do {
        cont = false; //shall the game continue?
        //Player one turn
        turn(p1, p2, board, c);
        cont = brdCheck(p1.min, p1.max, board);
        if (!cont) {
            addRocks(p2, board);
        }

        //Player two turn
        if (cont) {
            turn(p2, p1, board, c);
            cont = brdCheck(p2.min, p2.max, board);
            if (!cont) {
                addRocks(p1, board);
            }
        }
    } while (cont);

    dBrd(board, p1, p2);

    //Determining winner
    cout << "The game is over!\n";
    p1.points == p2.points ? cout << "It's a tie!" :
            p1.points > p2.points ? cout << "Player 1 " << p1.name << " wins!" : cout << "Player 2 " << p2.name << " wins!";

    if (p1.points > p2.points) {
        storePoints(p1);
    }
    if (p1.points < p2.points) {
        storePoints(p2);
    }

}

void User::storePoints(Player p) {

    // Open the file in binary mode for input and output
    fstream inFile("UserInfo.bin", ios::in | ios::out | ios::binary);

    if (!inFile) {
        cout << "Error: Could not open file. UserInfo.bin" << endl;
        return;
    }

    // Read data from the file into a User struct
    user userInfo;
    bool p1Updated = false;
    while (inFile.read((char*) &userInfo, sizeof (userInfo))) {

        // Update player 1's score if their name matches
        if (strcmp(p.name, userInfo.Username) == 0) {
            userInfo.score += 1;
            inFile.seekp(-static_cast<int> (sizeof (userInfo)), ios::cur);
            inFile.write((char*) &userInfo, sizeof (userInfo));
            p1Updated = true;
        }
        // Update player 2's score if their name matches

    }

    inFile.close();
}

void User::Start(Player &p1, Player &p2, int &pnum, int board[]) {
    bool END = false;
    ADMIN ADMIN;
    while (pnum < 3) {
S:
        int Select = 0;
        cout << "Mancala Game Player #" << pnum << endl;
        cout << "(1)Login" << endl;
        cout << "(2)Admin" << endl;
        cout << "(3)Create Account" << endl;
        cout << "(4)View Scores" << endl;
        cin >> Select;
        switch (Select) {
            case 1:
                Login(p1, p2, pnum, board);
                break;
            case 2:
                ADMIN.AdminLogin();
                pnum = 0;
                break;
            case 3:
                CreateAcc(p1, p2, pnum, board);
                break;
            case 4:
                ViewScores();
                pnum = 0;
                break;
            default:
                cerr << "This is a invalid choice" << endl;
                goto S;
                break;
        }

        pnum++;
    }

    if (END == false) {
        Play(p1, p2, board);
    } else {
        return;
    }

}

void User::ViewScores() {
    ifstream inFile("UserInfo.bin", ios::in | ios::binary);

    if (!inFile) {
        cout << "Error: Could not open file. UserInfo.bin" << endl;

    }

    int count = 0;
    // Read data from the file into a Data struct
    user UserInfo;
    while (inFile.read((char*) &UserInfo, sizeof (UserInfo))) {
        count++;
        cout << "User #" << count << endl;
        cout << "Username: " << UserInfo.Username << endl;
        cout << "Won: " << UserInfo.score << endl << endl;

    }

    // Close the file
    inFile.close();

}

void User::Login(Player &p1, Player &p2, int &pnum, int board[]) {


    char UserName[20];
    char Pass[20];
    cout << "Enter Your UserName To Login" << endl;
    cin >> UserName;

    bool found = false;

    // Open the binary file for reading
    ifstream inFile("UserInfo.bin", ios::in | ios::binary);

    if (!inFile) {
        cout << "Error: Could not open file. UserInfo.bin" << endl;

    }

    // Read data from the file into a Data struct
    user UserInfo;
    while (inFile.read((char*) &UserInfo, sizeof (UserInfo))) {



        if (strcmp(UserInfo.Username, UserName) == 0) {
T:
            cout << "Enter the Password" << endl;
            cin >> Pass;
            
            if (strcmp(UserInfo.Password, Pass) == 0) {
                if (pnum == 1) {
                    strcpy(p1.name, UserInfo.Username);
                    found = true;
                } else if (pnum == 2) {
                    strcpy(p2.name, UserInfo.Username);

                    found = true;
                }
            } else {
                cerr << "INVALID PASSWORD\nTRY AGAIN";
                goto T;
            }
        }


    }


    if (found == false) {
        int err;
q:
        cout << "There Are No UserNames That Match That\n(1)Create A Account\n(2)Try A Different Username\n" << endl;
        cin >> err;
        switch (err) {
            case 1:
                found = false;
                CreateAcc(p1, p2, pnum, board);
                break;
            case 2:
                found = false;
                Login(p1, p2, pnum, board);
                break;
            default:
                cout << "Input Error" << endl;
                goto q;
        }

    }

    //    count++;


    // Close the file
    inFile.close();
    found = false;


}

void User::CreateAcc(Player &p1, Player &p2, int &pnum, int board[]) {

    user U;

    cout << "**Create Account**" << endl;
    cout << "Enter Email" << endl; //need to be in html format <label></label>
    cin >> U.Email;

    cout << "Enter username" << endl;
    cin >> U.Username;

    cout << "Enter Password" << endl;
    cin >> U.Password;

    U.score = 0;


    ofstream outFile("UserInfo.bin", ios::out | ios::binary | ios::app);
    if (!outFile) {
        cout << "Error: Could not open file." << endl;
    }

    outFile.write((char*) &U, sizeof (U));
    outFile.close();

    cout << "Your Info has been stored you can login now" << endl;

    Start(p1, p2, pnum, board);

}

void User::addRocks(Player &p, int board[]) {
    int sum = 0;

    for (int i = p.min; i <= p.max; i++) {
        sum += board[i];
        board[i] = 0;
    }

    p.points += sum;
}

bool User::brdCheck(int min, int max, int board[SIZE]) {
    int sum = 0;

    for (int i = min; i <= max; i++) {
        sum += board[i];
    }

    if (sum == 0) return false;
    else return true;
}

void User::setBoard(int board[SIZE]) {
    //Setting Board
    for (int i = 0; i < SIZE; i++) {
        board[i] = 4;
    }

}

void User::turn(Player &p, const Player &p2, int board[SIZE], int &c) {
R:
    bool continueG = false;
    char choice; //user input
    int hand; //rocks in hand
    int mvs = 1; //number of moves
    int handcount = 0;

    cout << "It is now " << p.name << "'s turn!\n"; //********************
    cout << "Please enter a choice: ";
    cin>>choice;
    choice = toupper(choice); //capitalize if not already capitalized

    choice = valChoice(choice, p.min, p.max, board); //validating the users choice

    cout << "Choice is: " << choice << endl;
    choice -= 65; //Choice is now an integer that represents index of board
    hand = board[choice];
    handcount = hand;
    cout << endl << p.name << " picked up " << hand << " rocks from index " << board[choice] << endl;

    do {
        cout << "\nMove " << mvs << endl; //displays what move player is on
        hand = board[choice]; //pick up ricks at current index
        cout << "Hand is " << hand << endl; //displays rocks in hand

        //displays rocks from current index
        cout << "Board at index " << (char) (choice + 65) << " is " << board[choice] << endl;

        board[choice] = 0; //sets index to 0 because rocks are in hand now
        for (int i = 0; i < hand; i++) {
            choice += 1; //advances to next hole to drop rock

            //point system
            if (choice == p.max + 1) {//add stones to the players points.
                p.points++;
                if (i == hand - 1) {
                    cout << "***You landed on your own point slot you get another turn***" << endl;
                    if (c % 2 == 0) {
                        dBrd(board, p, p2);
                        continueG = brdCheck(p.min, p.max, board);
                        if (continueG == false) {
                            break;
                        }
                    }
                    if (c % 2 == 1) {
                        dBrd(board, p2, p);
                        continueG = brdCheck(p.min, p.max, board);
                        if (continueG == false) {
                            break;
                        }
                    }
                    goto R;
                }

                hand--;
            }

            if (choice == 12) choice = 0; //if choice is at end reset back to beginning
            board[choice] += 1; //Adding rock to next hole
        }

        if (c % 2 == 0) {
            dBrd(board, p, p2);
        }
        if (c % 2 == 1) {
            dBrd(board, p2, p);
        }

        cout << endl;
        mvs++;
        handcount--;
        if (board[choice] == 0) {
            board[choice] = 1;
        }
    } while (board[choice] != 1);
    c++;
}

char User::valChoice(char choice, int min, int max, int board[SIZE]) {

    while (choice < (char) (min + 65) || choice > (char) (max + 65) || (board[choice - 65] == 0)) {
        if (board[choice - 65] == 0)
            cout << "There are no rocks in that hole!\n";
        else if (choice < (char) (min + 65) || choice > (char) (max + 65))
            cout << "That is out of bounds!\n";
        cout << "Please enter a choice: ";
        cin>>choice; //no need for getline because no spaces
        choice = toupper(choice); //capitalize if not already capitalized
    }

    return choice;
}

void User::dBrd(int B[SIZE], Player p1, Player p2) {
    cout << "_________________________________________\n";
    cout << "|      |  A   B   C   D   E   F  |      |\n";
    cout << "|  p2  |_________________________|  p1  |\n";
    cout << "|      | " << setw(2) << B[0] << "  " << setw(2) << B[1] << "  " << setw(2) << B[2] << "  " << setw(2) << B[3] << "  " << setw(2) << B[4] << "  " << setw(2) << B[5] << "  |      |\n";
    cout << "| " << setw(2) << p2.points << "   |-------------------------| " << setw(2) << p1.points << "   |\n";
    cout << "|      | " << setw(2) << B[11] << "  " << setw(2) << B[10] << "  " << setw(2) << B[9] << "  " << setw(2) << B[8] << "  " << setw(2) << B[7] << "  " << setw(2) << B[6] << "  |      |\n";
    cout << "|      |_________________________|      |\n";
    cout << "|      |  L   K   J   I   H   G  |      |\n";
    cout << "_________________________________________\n";
}