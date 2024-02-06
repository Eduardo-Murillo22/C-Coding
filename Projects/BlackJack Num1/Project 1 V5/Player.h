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
    int money;
    string name;
    queue<int> betQueue;

public:
    Player() : money(0), name("") {
    }

    // Parameterized constructor

    Player(const string& Pname, int PM) : name(Pname), money(PM) {
    }

    void modeBet(int value);

    void Bet(int value);

    void Money(int newMoney);

    int getBet();

    int getTotalMoney() const;

    // Getter for money

    int getMoney() const;

    // Getter for name

    string getName() const;
};

#endif /* PLAYER_H */

