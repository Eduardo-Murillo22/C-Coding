
/* 
 * File:   main.cpp
 * Author: Eduardo Murillo
 *
 * Created on November 7, 2023, 8:52 PM
 * 
 * Black jack game
 * With currency 
 * and with multiple players
 * 
 * 
 */

#include <iostream>
#include <map>
#include <string>
#include <ctime>


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

    Deck() {

        for (int i = 0; i < 52; i++) {
            cardValues[deckname[i]] = calculateCardValue(deckname[i]); // Calculate card values
        }
        
        // Initialize the map in the constructor
        //Formate for the cards
        /* 
         * |======|
         * |A     |
         * |  ♠   |
         * |     A|
         * |======|
         * 
         * this is the formate that i need to acheive
         */
        cards["AS"] = "|======|\n|A     |\n|  ♠   |\n|     A|\n|======|";
        cards["2S"] = "|======|\n|2     |\n|  ♠   |\n|     2|\n|======|";
        cards["3S"] = "|======|\n|3     |\n|  ♠   |\n|     3|\n|======|";
        cards["4S"] = "|======|\n|4     |\n|  ♠   |\n|     4|\n|======|";
        cards["5S"] = "|======|\n|5     |\n|  ♠   |\n|     5|\n|======|";
        cards["6S"] = "|======|\n|6     |\n|  ♠   |\n|     6|\n|======|";
        cards["7S"] = "|======|\n|7     |\n|  ♠   |\n|     7|\n|======|";
        cards["8S"] = "|======|\n|8     |\n|  ♠   |\n|     8|\n|======|";
        cards["9S"] = "|======|\n|9     |\n|  ♠   |\n|     9|\n|======|";
        cards["10S"] = "|======|\n|10    |\n|  ♠   |\n|    10|\n|======|";
        cards["JS"] = "|======|\n|J     |\n|  ♠   |\n|     J|\n|======|";
        cards["QS"] = "|======|\n|Q     |\n|  ♠   |\n|     Q|\n|======|";
        cards["KS"] = "|======|\n|K     |\n|  ♠   |\n|     K|\n|======|";

        
        
        cards["AC"] = "|======|\n|A     |\n|  ♣   |\n|     A|\n|======|";
        cards["2C"] = "|======|\n|2     |\n|  ♣   |\n|     2|\n|======|";
        cards["3C"] = "|======|\n|3     |\n|  ♣   |\n|     3|\n|======|";
        cards["4C"] = "|======|\n|4     |\n|  ♣   |\n|     4|\n|======|";
        cards["5C"] = "|======|\n|5     |\n|  ♣   |\n|     5|\n|======|";
        cards["6C"] = "|======|\n|6     |\n|  ♣   |\n|     6|\n|======|";
        cards["7C"] = "|======|\n|7     |\n|  ♣   |\n|     7|\n|======|";
        cards["8C"] = "|======|\n|8     |\n|  ♣   |\n|     8|\n|======|";
        cards["9C"] = "|======|\n|9     |\n|  ♣   |\n|     9|\n|======|";
        cards["10C"] = "|======|\n|10    |\n|  ♣   |\n|    10|\n|======|";
        cards["JC"] = "|======|\n|J     |\n|  ♣   |\n|     J|\n|======|";
        cards["QC"] = "|======|\n|Q     |\n|  ♣   |\n|     Q|\n|======|";
        cards["KC"] = "|======|\n|K     |\n|  ♣   |\n|     K|\n|======|";
        
        

        cards["AD"] = "|======|\n|A     |\n|  ◆   |\n|     A|\n|======|";
        cards["2D"] = "|======|\n|2     |\n|  ◆   |\n|     2|\n|======|";
        cards["3D"] = "|======|\n|3     |\n|  ◆   |\n|     3|\n|======|";
        cards["4D"] = "|======|\n|4     |\n|  ◆   |\n|     4|\n|======|";
        cards["5D"] = "|======|\n|5     |\n|  ◆   |\n|     5|\n|======|";
        cards["6D"] = "|======|\n|6     |\n|  ◆   |\n|     6|\n|======|";
        cards["7D"] = "|======|\n|7     |\n|  ◆   |\n|     7|\n|======|";
        cards["8D"] = "|======|\n|8     |\n|  ◆   |\n|     8|\n|======|";
        cards["9D"] = "|======|\n|9     |\n|  ◆   |\n|     9|\n|======|";
        cards["10D"] = "|======|\n|10    |\n|  ◆   |\n|    10|\n|======|";
        cards["JD"] = "|======|\n|J     |\n|  ◆   |\n|     J|\n|======|";
        cards["QD"] = "|======|\n|Q     |\n|  ◆   |\n|     Q|\n|======|";
        cards["KD"] = "|======|\n|K     |\n|  ◆   |\n|     K|\n|======|";
        

        cards["AH"] = "|======|\n|A     |\n|  ♥   |\n|     A|\n|======|";
        cards["2H"] = "|======|\n|2     |\n|  ♥   |\n|     2|\n|======|";
        cards["3H"] = "|======|\n|3     |\n|  ♥   |\n|     3|\n|======|";
        cards["4H"] = "|======|\n|4     |\n|  ♥   |\n|     4|\n|======|";
        cards["5H"] = "|======|\n|5     |\n|  ♥   |\n|     5|\n|======|";
        cards["6H"] = "|======|\n|6     |\n|  ♥   |\n|     6|\n|======|";
        cards["7H"] = "|======|\n|7     |\n|  ♥   |\n|     7|\n|======|";
        cards["8H"] = "|======|\n|8     |\n|  ♥   |\n|     8|\n|======|";
        cards["9H"] = "|======|\n|9     |\n|  ♥   |\n|     9|\n|======|";
        cards["10H"] = "|======|\n|10    |\n|  ♥   |\n|    10|\n|======|";
        cards["JH"] = "|======|\n|J     |\n|  ♥   |\n|     J|\n|======|";
        cards["QH"] = "|======|\n|Q     |\n|  ♥   |\n|     Q|\n|======|";
        cards["KH"] = "|======|\n|K     |\n|  ♥   |\n|     K|\n|======|";
        
    }

    
    int calculateCardValue(const string& cardCode) {
        char rank = cardCode[0];
        if ((rank >= '2' && rank <= '9')) {
            return isdigit(rank) ? (rank - '0') : 10;
        }else if(rank == 'A'){
            return 11;
        }
        else {
            return 10; // Face cards (J, Q, K) all have a value of 10
        }
    }
    
    void displayDeck() {
        for (const auto& card : cards) {
            cout << "Card: " << card.first << endl;
            cout << card.second << endl;
        }
    }

    void disCard(const string& cardCode) {
        auto it = cards.find(cardCode);
        if (it != cards.end()) {
            cout << it->second << endl;
            cards.erase(it); // Remove the drawn card from the deck
        } else {
            cout << "----------------Card not found in the deck.----------------" << endl;
        }
    }

    
    int draw(const string& cardCode) {
        auto it = cardValues.find(cardCode);
        if (it != cardValues.end()) {
            
            return it->second;
            
        } else {
            cout << "Card not found in the deck." << endl;
            return 0; // Return 0 if the card is not found
        }
    }
     
    
    void shuffle(){
    int numCards = sizeof (deckname) / sizeof (deckname[0]);
        // Seed the random number generator with the current time
        srand(static_cast<unsigned> (time(nullptr)));

        // Perform Fisher-Yates shuffle
        for (int i = numCards - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(deckname[i], deckname[j]);
        }   
    }
    
};

class Dealer{
private:
    Deck myDeck;
    int totalP = 0;
    int i=2;
    int dealerTotal = 0;
    string Player;
    
public:
    
    
    Dealer(){
        myDeck.shuffle();
        cout << "Dealers Draw:" << endl;
        for (int x = 0; x < 2; x++) {
            string cardCode = myDeck.deckname[x];
            int cardValue = myDeck.draw(cardCode);
            dealerTotal += cardValue;

            myDeck.disCard(myDeck.deckname[x]);
        }
        cout << "Dealer Total: " << dealerTotal << endl;
        
    }

    int deal(const string& player) {
        Player = player;

        cout << player << " drew: " << endl;
        
        
        for (int x = i; x < i+2; x++) {
            string cardCode = myDeck.deckname[x];
            int cardValue = myDeck.draw(cardCode);
            totalP += cardValue;

            myDeck.disCard(myDeck.deckname[x]);
        }
        i+=2;

        cout << "Total: " << totalP << endl << endl;
        return totalP;
    }

    int newcard() {
        cout << Player << i << " drew a new card: " << endl;

        string cardCode = myDeck.deckname[i];
        int cardValue = myDeck.draw(cardCode);
        totalP += cardValue;

        myDeck.disCard(myDeck.deckname[i]);

        cout << "New Total: " << totalP << endl << endl;
        i++;
        return totalP;
    }
    

};

struct Player {
    int money;
    string name;

    Player(const string& playerName, int initialMoney) {
        name = playerName;
        money = initialMoney;
    }
};

int main(int argc, char** argv) {
    Dealer dealer;
    Player player("Eduardo", 200);
    
    char option;

    int playerTotal = dealer.deal(player.name);

    
    if (playerTotal == 21) {
        cout << "Blackjack! " << player.name << " wins!" << endl;
        player.money += 1.5 * player.money;
    } else if (playerTotal > 21) {
        cout << player.name << " busts!" << endl;
        player.money -= 0.5 * player.money; // Player loses half of the money on a bust.
    }

    cout << player.name << " has $" << player.money << " left." << endl;

    // Ask if the player wants to draw a new card
    cout << "New card? (Y/N): ";
    cin >> option;

    if (option == 'Y' || option == 'y') {
        int newTotal = dealer.newcard();

        if (newTotal == 21) {
            cout << "Blackjack! " << player.name << " wins!" << endl;
            player.money += 1.5 * player.money;
        } else if (newTotal > 21) {
            cout << player.name << " busts!" << endl;
            player.money -= 0.5 * player.money;
        }

        cout << player.name << " has $" << player.money << " left." << endl;
    }

    return 0;
}