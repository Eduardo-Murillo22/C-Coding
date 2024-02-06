/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   Player.h
 * Author: HP Omen
 *
 * Created on November 11, 2023, 8:55 PM
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <map>
#include <string>
#include <ctime>
#include <queue>
#include <set>
#include <list>
#include <stack>


using namespace std;

class Player {
private:
    set<int> money; // Change money to a set
    string name;
    queue<int> betQueue;
    int wins=0;

public:
    Player() : name("") {
    }

    // Parameterized constructor
    Player(const string& Pname, int PM) : name(Pname) {
        money.insert(PM); // Insert the initial money value into the set
    }

    void modeBet(int value);

    void Bet(int value);

    void Money(int newMoney);

    int getBet();

    int getMoney() const; // Change return type to set

    // Getter for name
    string getName() const;
    
    void Win();
    
    int GetWin();
};


#endif /* PLAYER_H */

