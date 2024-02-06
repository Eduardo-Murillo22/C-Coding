#include <iostream>
#include <map>
#include <string>
#include <ctime>
#include <queue>
#include <set>
#include <list>
#include <stack>

#include"Player.h"

void Player::modeBet(int value) {
    betQueue.emplace(value * 2);
    int currentMoney = *money.begin();
    
    money.erase(currentMoney); // Remove the old money value from the set
    
    money.insert(currentMoney - value); // Insert the new money value into the set
    
}

void Player::Bet(int value) {
    betQueue.emplace(value);
    int currentMoney = *money.begin();
    
    money.erase(currentMoney); // Remove the old money value from the set
    
    money.insert(currentMoney - value); // Insert the new money value into the set
    
}

void Player::Money(int newMoney) {
    money.erase(money.begin()); // Remove the old money value from the set
    money.insert(newMoney); // Insert the new money value into the set
}

int Player::getBet() {
    return betQueue.back();
}

int Player::getMoney() const {
    return *money.begin();
}

string Player::getName() const {
    return name;
}

void Player::Win(){
    wins += 1;
}

int Player::GetWin(){
    
    return wins;
    
}
    