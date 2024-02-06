/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   UserClass.h
 * Author: HP Omen
 *
 * Created on May 5, 2023, 11:16 AM
 */

#ifndef USERCLASS_H
#define USERCLASS_H
#include"PlayerInfo.h"
const int SIZE = 12;

class User{
   

    
public:
    void setBoard(int []);
    void dBrd(int [], Player, Player); //Eduardo
    void turn(Player &, const Player &, int [], int&); //Joe
    bool brdCheck(int, int, int[]);
    char valChoice(char, int, int, int []);
    void addRocks(Player &, int []);

    void Login(Player &, Player &, int &, int []); //user

    void Start(Player &, Player &, int &, int []); //both

    

    void CreateAcc(Player &, Player &, int &, int []); //user


    void storePoints(Player); //user
    void ViewScores(); //both
    void Play(Player &, Player &, int []); //user
    
};

#endif /* USERCLASS_H */

