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
        money -= value;

    }

    void Player::Bet(int value) {
        betQueue.emplace(value);
        money -= value;
    }

    void Player::Money(int newMoney) {
        money = newMoney;
    }

    int Player::getBet() {

        return betQueue.back();
    }

    int Player::getTotalMoney() const {
        return money;
    }

    // Getter for money

    int Player::getMoney() const {
        return money;
    }

    // Getter for name

    string Player::getName() const {
        return name;
    }
