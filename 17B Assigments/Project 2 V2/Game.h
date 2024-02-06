/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   Game.h
 * Author: HP Omen
 *
 * Created on December 9, 2023, 11:50 PM
 */

#ifndef GAME_H
#define GAME_H
#include"Player.h"

class Game{
private:
    
    bool PLAY;
    int Nplay = 0;
    int MAX_PLAYERS = 4;
public:

    void Play(Player players[], int Nplay, int[]);
    int start();
    
};

#endif /* GAME_H */

