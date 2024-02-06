
/* 
 * File:   main.cpp
 * Author: Eduardo Murillo
 *
 * Created on December 8, 2023, 8:52 PM
 * 
 * Black jack game
 * With currency 
 * and with multiple players
 * 
 * 
 */

#include <iostream>

#include"Game.h"

const int MAX_PLAYERS = 4;

int main(int argc, char** argv) {
    Game GAME;
    GAME.start();
    
    return 0;
}