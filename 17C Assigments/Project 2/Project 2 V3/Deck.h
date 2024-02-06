/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   Deck.h
 * Author: HP Omen
 *
 * Created on November 11, 2023, 8:54 PM
 */

#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <map>
#include <string>
#include <ctime>
#include <queue>
#include <set>
#include <list>
#include <stack>

using namespace std;


class Deck{
private:
    map<string, string> cards;
    
public:

    map<string, int> cardValues; 
    string deckname[52] = {
        "AS", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "10S", "JS", "QS", "KS",
        
        "AC", "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "10C", "JC", "QC", "KC",
        
        "AD", "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "10D", "JD", "QD", "KD",
        
        "AH", "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "10H", "JH", "QH", "KH"
    };

    Deck();

    
    int calculateCardValue(const string& cardCode);
    
    void displayDeck();

    void disCard(const string& cardCode,int numCard);

    
    int draw(const string& cardCode);
     
    
    void shuffle();
    
};


#endif /* DECK_H */

