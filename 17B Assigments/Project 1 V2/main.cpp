
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
    
    
    int DealerCards(){
        myDeck.shuffle();
        cout << "Dealers Draw:" << endl;
        for (int x = 0; x < 2; x++) {
            string cardCode = myDeck.deckname[x];
            int cardValue = myDeck.draw(cardCode);
            dealerTotal += cardValue;

            myDeck.disCard(myDeck.deckname[x]);
        }
        cout << "Dealer Total: " << dealerTotal << endl;
        return dealerTotal;        
    }

    int deal(const string& player) {
        Player = player;
        
        int totalP = 0;

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
        int totalP = 0;
        string cardCode = myDeck.deckname[i];
        int cardValue = myDeck.draw(cardCode);
        totalP += cardValue;

        myDeck.disCard(myDeck.deckname[i]);

        
        i++;
        return totalP;
    }
    
    

};

class Player {
private:
    int money;
    string name;
    int bet;
    
public:
    
    //Default constructor set all to nothing
    Player() : money(0), name("") {}
    
    // Parameterized constructor
    Player(string Pname, int PM){
        
        name = Pname;
        money = PM;
        
    }

    int Bet(int value){
        bet = value;
        money -= value;
    }
    
    
    
    int getBet(){
        return bet;
    }

    // Getter for money

    int getMoney() const {
        return money;
    }

    // Getter for name

    string getName() const {
        return name;
    }
    
};

int main(int argc, char** argv) {
//    Dealer dealer;
    
    int Nplay=0;
    
    cout << "How Many players would like to play ? max of 4" << endl;
    cin >> Nplay;

    // Validate the number of players
    if (Nplay <= 0 || Nplay > 4) {
        cout << "Invalid number of players. Exiting..." << endl;
        return 1; // Exit with an error code
    }
    
    Player* players = new Player[Nplay];
    
    for(int i =0; i < Nplay;i++){
        
        string playername;
        cout << "Enter the name for the player # " << i+1 << " : " << endl;
        cin >> playername;
        
        int MONEY;
        cout << "Enter also there starting money: " << endl;
        cin >> MONEY;
        
        players[i] = Player(playername,MONEY);
        
    }

    bool isInputValid = false;

    while (!isInputValid) {
        cout << "Is this correct?" << endl;

        for (int i = 0; i < Nplay; i++) {
            cout << "+++++Player #" << i + 1 << ": ";
            cout << players[i].getName() << ", $" << players[i].getMoney() << "+++++" << endl << endl;
        }

        cout << "Enter Y for yes or N for no" << endl;
        char correct;
        cin >> correct;

        correct = toupper(correct);

        if (correct == 'Y') {
            cout << "Let's start..." << endl;
            isInputValid = true; // Exit the loop
        } else if (correct == 'N') {
            cout << "Okay, let's start over..." << endl;
            return 0;
        } else {
            cout << "Incorrect input. Try again..." << endl << endl;
        }
    }
    
    int Bet;
    for(int i=0;i < Nplay;i++){

        if (players[i].getMoney() < 10) {
            
            cout << "Player #" << i + 1 << " " << players[i].getName() << ", you don't have enough money to play." << endl;
            cout << "Do you want to add more money? (Enter Y for yes, N for no)" << endl; 
            
            
            char addMoreMoney;
            cin >> addMoreMoney;

            if (toupper(addMoreMoney) == 'Y') {
                
                int additionalMoney;
                
                cout << "Enter the amount of additional money: " << endl;
                cin >> additionalMoney;
                
                players[i].Bet(-additionalMoney); // Adding money (negative bet)
                cout << "Remaining Balance = $" << players[i].getMoney() << endl;
            }else {
                cout << "You chose not to add more money. You are not in the game." << endl;
                continue; // Skip the turn
            }
        }
        
        cout << players[i].getName() << ", enter your bet (MIN = 10): " << endl;
        cin >> Bet;
        
        while(Bet < 10){
            cout << "You need to bet 10 or higher" << endl;
            cin >> Bet;
        }
        
        players[i].Bet(Bet);
        
        cout << "Remanding Balance = $" << players[i].getMoney() << endl;
        

        
    }
    

    cout << endl;
    Dealer dealer;
    int dealerValue = dealer.DealerCards();
    if(dealerValue > 21){
        
        //validation if dealer gets double ace = 11 + 11 = 22
        //make sure that if he gets that i considers one of the aces
        // as a 1.
        dealerValue -= 10;
        
    }
    int* PlayerCardV = new int[Nplay]; 
    
    for(int i =0;i < Nplay;i++){
        
        //Gives cards to the players with at valid bet
        if(players[i].getBet() >= 10){
            // Deal the cards to the player.
            PlayerCardV[i] = dealer.deal(players[i].getName());
        }   
    }

    
    for (int i = 0; i < Nplay; i++) {
        
        //bool to see if the player wants more cards
        bool moreCards = true;
        //counter to see how many cards the player has taken
        int countOfCards =0;
        while(moreCards == true){
            if(players[i].getBet() >= 10){

                if(PlayerCardV[i] == 21){

                    cout << players[i].getName() <<  " BlackJack!!" << endl;
                }
                else{

                    cout << endl;
                    cout << endl;
                    cout << players[i].getName() << ", you have a card count of " << PlayerCardV[i] << endl;
                    cout << "What would you like to do?" << endl;
                    int choice;
                    bool x=false;
                    //give double option if its the first new card delt
                    if(countOfCards == 0){
                        while (x == false) {
                            cout << "1. Hit" << endl;
                            cout << "2. Settle" << endl;
                            cout << "3. Double down" << endl;
                            cout << "Enter your choice: ";

                            cin >> choice;

                            switch (choice) {
                                case 1:{
                                    int newCard = 0;
                                    newCard = dealer.newcard();
                                    if(newCard == 11 && PlayerCardV[i] > 11 ){
                                        newCard = 1;
                                    }
                                    PlayerCardV[i] += newCard;
                                    //if players count is higher then 21 then dont give more cards
                                    if (PlayerCardV[i] > 21) {
                                        cout << PlayerCardV[i] << " " << endl;
                                        cout << "You lost already" << endl;
                                        moreCards = false;
                                    }
                                    //if player count is 21 tell them that have 21
                                    if (PlayerCardV[i] == 21) {
                                        cout << "Black Jack!!" << endl;
                                        moreCards = false;
                                    }
                                    // Perform actions for Hit
                                    break;
                                }

                                case 2:

                                    moreCards = false;
                                    // Perform actions for Settle
                                    break;

                                case 3:{
                                        int b = players[i].getBet();
                                        b = b*2;
                                        players[i].Bet(b);

                                        int newCard = 0;
                                        newCard = dealer.newcard();
                                        if (newCard == 11 && PlayerCardV[i] > 11) {
                                            newCard = 1;
                                        }
                                        PlayerCardV[i] += newCard;
                                        moreCards = false;

                                        // Perform actions for Double down
                                        break;
                                    }

                                default:

                                    cout << "Invalid choice. Please enter a valid option." << endl;
                                    continue; // Repeat the loop for an invalid choice
                            }

                            x=true; // Exit the loop if a valid choice is made
                        }
                    }
                    else{
                            while (x == false) {
                                cout << "1. Hit" << endl;
                                cout << "2. Settle" << endl;
                                cout << "Enter your choice: ";

                                cin >> choice;

                                switch (choice) {
                                    case 1:
                                    {
                                        
                                        int newCard = 0;
                                        newCard = dealer.newcard();
                                        if (newCard == 11 && PlayerCardV[i] > 11) {
                                            newCard = 1;
                                        }
                                        PlayerCardV[i] += newCard;
                                        //if players count is higher then 21 then dont give more cards
                                        if(PlayerCardV[i] > 21){
                                            cout << PlayerCardV[i] << " " << endl;
                                            cout << "You lost already" << endl;
                                            moreCards = false;
                                        }
                                        //if player count is 21 tell them that have 21
                                        if(PlayerCardV[i] == 21){
                                            cout << "Black Jack!!" << endl;
                                            moreCards = false;
                                        }
                                        // Perform actions for Hit
                                        break;
                                    }

                                    case 2:
                                        moreCards = false;
                                        break;
                                    
                                    default:

                                        cout << "Invalid choice. Please enter a valid option." << endl;
                                        continue; // Repeat the loop for an invalid choice
                                }

                                x = true; // Exit the loop if a valid choice is made
                            
                        }
                    }
                }
                countOfCards++;
            }
        }
    }
    
    

    //delete dynamic players
    delete[] PlayerCardV;
    delete[] players;
    return 0;
}
































































































































