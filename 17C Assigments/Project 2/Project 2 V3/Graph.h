/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   Graph.h
 * Author: HP Omen
 *
 * Created on December 10, 2023, 11:34 PM
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <unordered_map>
using namespace std;

class Graph {
private:
    unordered_map<string, int> adjacencyList;

public:

    void addPlayer(const string& playerName) {
        // Reset the card value for the player each time a new game starts
        adjacencyList[playerName] = 0;
    }

    void addCard(const string& player, int cardValue) {
        // Assuming cardValue is an integer representing the card value
        // You can add any logic here based on your requirements
        adjacencyList[player] += cardValue;
    }

    void displayPlayerCards() {
        for (const auto& entry : adjacencyList) {
            cout << entry.first << "'s Cards Value: " << entry.second << endl;
        }
    }
};



#endif /* GRAPH_H */

