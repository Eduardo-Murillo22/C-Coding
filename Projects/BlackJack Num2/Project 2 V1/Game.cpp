#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <ctime>
#include <queue>
#include <set>
#include <list>
#include <stack>

using namespace std;

#include"Player.h"
#include"Dealer.h"
#include"Deck.h"

#include"Game.h"

class Node {
public:
    string data;
    Node* left;
    Node* right;
    // Val is the key or the value that
    // has to be added to the data part

    Node(string val) {
        data = val;
        // Left and right child for node
        // will be initialized to null
        left = NULL;
        right = NULL;
    }
};

int hashPlayerName(const string& playerName, int maxSize) {
    // Simple hash function, you can replace it with a better one if needed
    int hash = 0;
    for (char ch : playerName) {
        hash = hash * 31 + ch;
    }
    cout << abs(hash) % maxSize << endl;
    return abs(hash) % maxSize;
}

int Game::start(){
    cout << "WELCOME TO BLACKJACK" << endl;

    cout << "Let's start the game!" << endl;
    Nplay = 0;

    cout << "How Many players would like to play ? max of " << MAX_PLAYERS << endl;
    cin >> Nplay;

    // Validate the number of players
    if (Nplay <= 0 || Nplay > MAX_PLAYERS) {
        cout << "Invalid number of players. Exiting..." << endl;
        return 0;
    }

    Player* players = new Player[MAX_PLAYERS];
    int* playIdex = new int[Nplay];

    for (int i = 0; i < Nplay; i++) {
        string playername;
        cout << "Enter the name for player #" << i + 1 << ": " << endl;
        cin >> playername;

        int MONEY;
        cout << "Enter also their starting money: " << endl;
        cin >> MONEY;

        // Hash the player's name to get an index
        int index = hashPlayerName(playername, MAX_PLAYERS);
        playIdex[i] = index;

        // Validate if the index is already occupied
        while (players[index].getName() != "") {
            cout << "Collision detected! Please enter a different name: ";
            cin >> playername;
            index = hashPlayerName(playername, MAX_PLAYERS);
            playIdex[i] = index;
        }

        players[index] = Player(playername, MONEY);
    }

        bool isInputValid = false;

        while (!isInputValid) {
            cout << "Is this correct?" << endl;

            for (int i = 0; i < Nplay; i++) {
                cout << "+++++Player #" << i + 1 << ": ";
                cout << players[playIdex[i]].getName() << ", $" << players[playIdex[i]].getMoney() << "+++++" << endl << endl;
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
                break;
            } else {
                cout << "Incorrect input. Try again..." << endl << endl;
            }
        }

        for (int i = 0; i < Nplay; i++) {

            if (players[playIdex[i]].getMoney() < 10) {

                cout << "Player #" << i + 1 << " " << players[playIdex[i]].getName() << ", you don't have enough money to play." << endl;
                cout << "Do you want to add more money? (Enter Y for yes, N for no)" << endl;


                char addMoreMoney;
                cin >> addMoreMoney;

                if (toupper(addMoreMoney) == 'Y') {

                    int additionalMoney;

                    cout << "Enter the amount of additional money: " << endl;
                    cin >> additionalMoney;

                    players[playIdex[i]].Bet(-additionalMoney); // Adding money (negative bet)
                    cout << "Remaining Balance = $" << players[playIdex[i]].getMoney() << endl;
                } else {
                    cout << "You chose not to add more money. You are not in the game." << endl;
                    continue; // Skip the turn
                }
            }
        }
        
        while(PLAY == true){
            Play(players,Nplay,playIdex);
        }
        
        delete[] players;
}


void Game::Play(Player players[],int Nplay,int playIdex[]){
    

    cout << endl;
    
    for(int i = 0;i < Nplay;i++){

        int Bet=0;

        cout << players[playIdex[i]].getName() << ", enter your bet (MIN = 10): " << endl;
        cin >> Bet;

        while (Bet < 10) {
            cout << "You need to bet 10 or higher" << endl;
            cin >> Bet;
        }

        players[playIdex[i]].Bet(Bet);

        cout << "Remanding Balance = $" << players[playIdex[i]].getMoney() << endl;
        if(players[playIdex[i]].getMoney() < 0){
            
            cout << "You don not have the money to play " << endl;
            PLAY = false;
            
        }
        
    }

    Dealer dealer;
    list<int> dealerValue;
    dealerValue.push_front(dealer.DealerCards());

    if (dealerValue.front() > 21) {
        // Validation if the dealer gets double ace = 11 + 11 = 22
        // Make sure that if he gets that, it considers one of the aces
        // as a 1.
        for (int& value : dealerValue) {
            value -= 10;
        }
    }

    int* PlayerCardV = new int[Nplay]; 
    
    for(int i =0;i < Nplay;i++){
        //Gives cards to the players with at valid bet
        if(players[playIdex[i]].getBet() >= 10){
            // Deal the cards to the player.
            PlayerCardV[i] = dealer.deal(players[playIdex[i]].getName());
        }   
    }
    
    Node* root = new Node("Black Jack!!");

    root->right = new Node("1. Hit\n2. Settle\n3. Double down\nEnter your choice: ");
    root->right->right = new Node("Black Jack!!");
    root->right->left = new Node("You lost already");

    root->left = new Node("1. Hit\n2. Settle\nEnter your choice: ");
    root->left->right = new Node("Black Jack!!");
    root->left->left = new Node("You lost already");
    for (int i = 0; i < Nplay; i++) {
        
        //bool to see if the player wants more cards
        bool moreCards = true;
        //counter to see how many cards the player has taken
        int countOfCards =0;
        while(moreCards == true){
            if(players[playIdex[i]].getBet() >= 10){

                if(PlayerCardV[i] == 21){

                    cout << players[playIdex[i]].getName() <<  root->data << endl;
                    moreCards = false;
                }
                else{

                    cout << endl;
                    cout << endl;
                    cout << players[playIdex[i]].getName() << ", you have a card count of " << PlayerCardV[i] << endl;
                    cout << "What would you like to do?" << endl;
                    int choice;
                    bool x=false;
                    //dont let player double if he has no money
                    if (players[playIdex[i]].getMoney() < players[playIdex[i]].getBet()*2) {
                        countOfCards++;

                    }


                    
                    //give double option if its the first new card delt
                    if(countOfCards == 0){
                        while (x == false) {                       

                            cout << root->right->data;
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
                                        cout << root->right->data << endl;
                                        moreCards = false;
                                    }
                                    //if player count is 21 tell them that have 21
                                    if (PlayerCardV[i] == 21) {
                                        cout << root->right->data << endl;
                                        moreCards = false;
                                    }
                                    // Perform actions for Hit
                                    break;
                                }

                                case 2:

                                    moreCards = false;
                                    // Perform actions for Settle
                                    break;

                                
                                case 3:
                                {
                                    int newBet = players[playIdex[i]].getBet();

                                    players[playIdex[i]].modeBet(newBet);

                                    int newCard = 0;
                                    newCard = dealer.newcard();
                                    if (newCard == 11 && PlayerCardV[i] + newCard > 21) {
                                        newCard = 1;
                                    }
                                    PlayerCardV[i] += newCard;

                                    // Perform actions for Double down
                                    moreCards = false;
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

                                cout << root->left->data << endl;
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
                                            cout << root->left->data << endl;
                                            moreCards = false;
                                        }
                                        //if player count is 21 tell them that have 21
                                        if(PlayerCardV[i] == 21){
                                            cout << root->left->data << endl;
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
    
    cout << endl;
    cout << endl;
    for (int i = 0; i < Nplay; i++) {
        cout << endl;
            if (players[playIdex[i]].getBet() >= 10) {
                if(PlayerCardV[i] > 21){
                    cout << players[playIdex[i]].getName() << " you have " << PlayerCardV[i] << " You Lost" << endl;
                }
                else if(PlayerCardV[i] == 21){
                    cout << players[playIdex[i]].getName() << root->data <<endl;
                }
                else{
                    cout << players[playIdex[i]].getName() << " has " << PlayerCardV[i];
                }    
        }
    }
    cout << endl;
    cout << endl;
    
    //dealer new cards for the dealer to compete the players
    cout << "Dealer Gets For Himself" << endl;

    dealerValue.push_front(dealer.dealerPlay());
    
    
    cout << endl <<endl <<endl;
    cout << "Dealers Card Value Is: " << dealerValue.front() << endl;
    for(int i =0;i < Nplay;i++){
        
        if(players[playIdex[i]].getBet() >= 10){
            
            cout << players[playIdex[i]].getName() << " Has " << PlayerCardV[i] << " And Has A Bet Of: ";
            cout << players[playIdex[i]].getBet() << " and you have $" << players[playIdex[i]].getMoney() << endl;
            
        }
        
    }

    cout << endl << endl;

    size_t size = dealerValue.size();

    // Create an array of the same size
    int* myArray = new int[size];

    // Copy elements from the list to the array
    copy(dealerValue.begin(), dealerValue.end(), myArray);
    
    sort(myArray, myArray + size);

    // Printing the array
    cout << "Hidden Card";
    for (size_t i = 0; i < size; ++i) {
        cout << "-> " << myArray[i] ;
    }
    cout << endl;

    // Don't forget to free the allocated memory
    delete[] myArray;

    for (int i = 0; i < Nplay; i++) {
        if (players[playIdex[i]].getBet() >= 10) {


            if (PlayerCardV[i] >= 22) {
                //got more than 21 take their bet away
                cout << players[playIdex[i]].getName() << ", You got more than 21 so you lose your bet." << endl;

            } else if (PlayerCardV[i] > dealerValue.front()) {

                cout << players[playIdex[i]].getName() << ", Congrats You Have " << PlayerCardV[i] << " and the dealer has " << dealerValue.front() << endl;
                cout << "This means you WON" << endl;

                int newMoneyTotal = (players[playIdex[i]].getBet() * 2) + players[playIdex[i]].getMoney();
                players[playIdex[i]].Money(newMoneyTotal);

            } else if (dealerValue.front() > 21) {
                // Dealer busts, player wins
                cout << players[playIdex[i]].getName() << ", The Dealer got more than 21, you win!" << endl;

                int newMoneyTotal = (players[playIdex[i]].getBet() * 2) + players[playIdex[i]].getMoney();
                players[playIdex[i]].Money(newMoneyTotal);
            } else if (PlayerCardV[i] < dealerValue.front()) {

                cout << players[playIdex[i]].getName() << ", Sorry You Lost you have " << PlayerCardV[i] << " and the dealer has " << dealerValue.front() << endl;
                cout << "This means you lost" << endl;

            } else {

                // It's a tie
                cout << players[playIdex[i]].getName() << ", You tied. You have: " << PlayerCardV[i] << " and the dealer has " << dealerValue.front() << endl;
                int newMoneyTotal = players[playIdex[i]].getBet() + players[playIdex[i]].getMoney();
                players[playIdex[i]].Money(newMoneyTotal);

            }

        }

    }

    
    cout << endl << endl;
    cout << "THIS IS THE PLAYERS: " << endl;
    for(int i =0;i < Nplay;i++){
        if(players[playIdex[i]].getBet() >= 10){
            
            
            cout << players[playIdex[i]].getName() << " = $" << players[playIdex[i]].getMoney() << endl; 
            
        }
        
    }
   


    bool keepPlay = false;
    char playInput;

    while (!keepPlay) {
        cout << "Would you like to play again? (Y/N)" << endl;
        cin >> playInput;
        playInput = toupper(playInput);

        if (playInput == 'Y') {
            // Keep playing
            cout << "Let's continue playing." << endl;
            keepPlay = true; // Set the flag to exit the loop
        } else if (playInput == 'N') {
            // Stop playing
            cout << "Okay, stopping the game." << endl;
            keepPlay = true; // Set the flag to exit the loop
            PLAY = false;
        } else {
            // Wrong input
            cout << "Invalid input. Please enter 'Y' or 'N'." << endl;
        }
    }

    // Don't forget to free the allocated memory
    delete[] PlayerCardV;
}
