/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   Dealer.h
 * Author: HP Omen
 *
 * Created on November 11, 2023, 8:55 PM
 */

#ifndef DEALER_H
#define DEALER_H

#include <iostream>
#include <map>
#include <string>
#include <ctime>
#include <queue>
#include <set>
#include <list>
#include <stack>

#include"Deck.h"


using namespace std;

class Dealer{
private:
    Deck myDeck;
    stack<int> totalP;
    int i = 2;
    int dealerTotal = 0;
    string Player;

public:
    int DealerCards();
    int deal(const string& player);
    int newcard();
    int getTotalFromStack() const;
    int dealerPlay();
    
};

#endif /* DEALER_H */

