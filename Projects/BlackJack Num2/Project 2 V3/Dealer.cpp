

#include <iostream>
#include <map>
#include <string>
#include <ctime>
#include <queue>
#include <set>
#include <list>
#include <stack>

#include"Dealer.h"


    int Dealer::DealerCards() {
        myDeck.shuffle();
        cout << "Dealers Draw:" << endl;
        for (int x = 0; x < 2; x++) {
            string cardCode = myDeck.deckname[x];
            int cardValue = myDeck.draw(cardCode);
            dealerTotal += cardValue;
            myDeck.disCard(myDeck.deckname[x], x + 1);
        }
        cout << " + the value of the hidden Card." << endl;
        return dealerTotal;
    }

    int Dealer::deal(const string& player) {
        Player = player;

        int playerTotal = 0;

        cout << player << " drew: " << endl;

        for (int x = i; x < i + 2; x++) {
            string cardCode = myDeck.deckname[x];
            int cardValue = myDeck.draw(cardCode);
            playerTotal += cardValue;

            myDeck.disCard(myDeck.deckname[x], 2);
        }
        i += 2;

        totalP.push(playerTotal);  // Push the player's total onto the stack
        cout << "Total: " << playerTotal << endl << endl;
        return playerTotal;
    }

    int Dealer::newcard() {
        int playerTotal = 0;
        string cardCode = myDeck.deckname[i];
        
        int cardValue = myDeck.draw(cardCode);
        playerTotal += cardValue;
        
        myDeck.disCard(myDeck.deckname[i], 2);

        totalP.push(playerTotal);  // Push the player's total onto the stack
        i++;
        return playerTotal;
    }

    int Dealer::dealerPlay() {
        while (dealerTotal < 17) {
            // Draw a new card for the dealer
            int newCard = newcard();

            // Check if the new card is an Ace and adjust its value if necessary
            if (newCard == 11 && dealerTotal + newCard > 21) {
                newCard = 1;
            }

            // Add the new card to the dealer's total
            dealerTotal += newCard;

            // Display the drawn card and the updated total
            cout << "Dealer draws a new card: " << newCard << endl;
            cout << "Dealer Total: " << dealerTotal << endl;
            i++;
        }

        // Check if the dealer's total is 17 or more
        if (dealerTotal >= 17) {
            cout << "The dealer Stays With A Value Of = " << dealerTotal << endl;
        }

        // Return the final total of the dealer's cards
        return dealerTotal;
    }
