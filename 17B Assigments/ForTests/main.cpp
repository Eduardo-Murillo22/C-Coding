#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

class Card {
public:
    Card(string suit, string rank) : suit(suit), rank(rank) {}

    int getValue() const {
        if (rank == "A") return 11;
        if (rank == "K" || rank == "Q" || rank == "J") return 10;
        return stoi(rank);
    }

    string getSuit() const {
        return suit;
    }

    string getRank() const {
        return rank;
    }

private:
    string suit;
    string rank;
};

class Deck {
public:
    Deck() {
        string suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
        string ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };

        for (const string &suit : suits) {
            for (const string &rank : ranks) {
                cards.push_back(Card(suit, rank));
            }
        }
    }

    void shuffle() {
        random_shuffle(cards.begin(), cards.end());
    }

    Card drawCard() {
        Card drawnCard = cards.back();
        cards.pop_back();
        return drawnCard;
    }

    bool isEmpty() const {
        return cards.empty();
    }

private:
    vector<Card> cards;
};

class Player {
public:
    Player(string name) : name(name) {}

    void receiveCard(Card card) {
        hand.push_back(card);
    }

    int getHandValue() const {
        int value = 0;
        int aces = 0;

        for (const Card &card : hand) {
            value += card.getValue();
            if (card.getRank() == "A") aces++;
        }

        while (value > 21 && aces > 0) {
            value -= 10;
            aces--;
        }

        return value;
    }

    void clearHand() {
        hand.clear();
    }

    string getName() const {
        return name;
    }

    const vector<Card>& getHand() const {
        return hand;
    }

private:
    string name;
    vector<Card> hand;
};

class BlackjackGame {
public:
    BlackjackGame() {
        deck.shuffle();
        players.push_back(Player("Player"));
        players.push_back(Player("Dealer"));
    }

    void dealInitialCards() {
        for (Player &player : players) {
            player.receiveCard(deck.drawCard());
        }

        for (Player &player : players) {
            player.receiveCard(deck.drawCard());
        }
    }

    void play() {
        dealInitialCards();

        while (true) {
            for (Player &player : players) {
                displayGameStatus();
                playerTurn(player);
                if (player.getHandValue() > 21) {
                    cout << player.getName() << " busts!" << endl;
                    return;
                }
            }

            if (players[1].getHandValue() >= 17) break;
            players[1].receiveCard(deck.drawCard());
        }

        displayGameStatus();
        determineWinner();
    }

private:
    Deck deck;
    vector<Player> players;

    void displayGameStatus() {
        for (const Player &player : players) {
            cout << player.getName() << "'s hand: ";
            for (const Card &card : player.getHand()) {
                cout << card.getRank() << " of " << card.getSuit() << ", ";
            }
            cout << "Total Value: " << player.getHandValue() << endl;
        }
        cout << endl;
    }

    void playerTurn(Player &player) {
        if (player.getName() == "Player") {
            cout << "Player's turn. Do you want to hit (h) or stand (s)? ";
            char choice;
            cin >> choice;

            if (choice == 'h') {
                player.receiveCard(deck.drawCard());
            }
        } else {
            if (player.getHandValue() < 17) {
                player.receiveCard(deck.drawCard());
            }
        }
    }

    void determineWinner() {
        int playerValue = players[0].getHandValue();
        int dealerValue = players[1].getHandValue();

        if (playerValue > 21) {
            cout << "Dealer wins. Player busts!" << endl;
        } else if (dealerValue > 21) {
            cout << "Player wins. Dealer busts!" << endl;
        } else if (playerValue > dealerValue) {
            cout << "Player wins!" << endl;
        } else if (dealerValue > playerValue) {
            cout << "Dealer wins!" << endl;
        } else {
            cout << "It's a tie!" << endl;
        }
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0)));
    BlackjackGame game;
    char playAgain = 'y';

    while (playAgain == 'y') {
        game.play();
        cout << "Play again? (y/n): ";
        cin >> playAgain;

        if (playAgain == 'y') {
            game = BlackjackGame(); // Reset the game
        }
    }

    return 0;
}
