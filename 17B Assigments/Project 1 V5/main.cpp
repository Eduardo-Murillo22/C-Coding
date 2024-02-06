
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
#include <algorithm>
#include <map>
#include <string>
#include <ctime>
#include <queue>
#include <set>
#include <list>
#include <stack>

#include"Player.h"
#include"Dealer.h"
#include"Deck.h"


void Play(bool &PLAY, Player players[], int Nplay);

int main(int argc, char** argv) {

    char PLAY;
    bool playing;

    cout << "WELCOME TO BLACKJACK" << endl;
   
        
        cout << "Let's start the game!" << endl;
        int Nplay = 0;

        cout << "How Many players would like to play ? max of 4" << endl;
        cin >> Nplay;

        // Validate the number of players
        if (Nplay <= 0 || Nplay > 4) {
            cout << "Invalid number of players. Exiting..." << endl;
            return 1;
        }

        Player* players = new Player[Nplay];

        for (int i = 0; i < Nplay; i++) {

            string playername;
            cout << "Enter the name for the player # " << i + 1 << " : " << endl;
            cin >> playername;

            int MONEY;
            cout << "Enter also there starting money: " << endl;
            cin >> MONEY;

            players[i] = Player(playername, MONEY);

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
                break;
            } else {
                cout << "Incorrect input. Try again..." << endl << endl;
            }
        }

        for (int i = 0; i < Nplay; i++) {

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
                } else {
                    cout << "You chose not to add more money. You are not in the game." << endl;
                    continue; // Skip the turn
                }
            }
        }
        
        while(playing == true){
            Play(playing,players,Nplay);
        }
        
        delete[] players;


    //delete dynamic players

    return 0;
}



void Play(bool &PLAY,Player players[],int Nplay){
    

    cout << endl;
    
    for(int i = 0;i < Nplay;i++){

        int Bet=0;

        cout << players[i].getName() << ", enter your bet (MIN = 10): " << endl;
        cin >> Bet;

        while (Bet < 10) {
            cout << "You need to bet 10 or higher" << endl;
            cin >> Bet;
        }

        players[i].Bet(Bet);

        cout << "Remanding Balance = $" << players[i].getMoney() << endl;
        if(players[i].getMoney() < 0){
            
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
                    moreCards = false;
                }
                else{

                    cout << endl;
                    cout << endl;
                    cout << players[i].getName() << ", you have a card count of " << PlayerCardV[i] << endl;
                    cout << "What would you like to do?" << endl;
                    int choice;
                    bool x=false;
                    //dont let player double if he has no money
                    if (players[i].getMoney() < players[i].getBet()*2) {
                        countOfCards++;

                    }
                    
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

                                
                                case 3:
                                {
                                    int newBet = players[i].getBet();

                                    players[i].modeBet(newBet);

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
    
    cout << endl;
    cout << endl;
    for (int i = 0; i < Nplay; i++) {
        cout << endl;
            if (players[i].getBet() >= 10) {
                if(PlayerCardV[i] > 21){
                    cout << players[i].getName() << " you have " << PlayerCardV[i] << " You Lost" << endl;
                }
                else if(PlayerCardV[i] == 21){
                    cout << players[i].getName() << " Black Jack!!" <<endl;
                }
                else{
                    cout << players[i].getName() << " has " << PlayerCardV[i];
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
        
        if(players[i].getBet() >= 10){
            
            cout << players[i].getName() << " Has " << PlayerCardV[i] << " And Has A Bet Of: ";
            cout << players[i].getBet() << " and you have $" << players[i].getMoney() << endl;
            
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
        if (players[i].getBet() >= 10) {


            if (PlayerCardV[i] >= 22) {
                //got more than 21 take their bet away
                cout << players[i].getName() << ", You got more than 21 so you lose your bet." << endl;

            } else if (PlayerCardV[i] > dealerValue.front()) {

                cout << players[i].getName() << ", Congrats You Have " << PlayerCardV[i] << " and the dealer has " << dealerValue.front() << endl;
                cout << "This means you WON" << endl;

                int newMoneyTotal = (players[i].getBet() * 2) + players[i].getMoney();
                players[i].Money(newMoneyTotal);

            } else if (dealerValue.front() > 21) {
                // Dealer busts, player wins
                cout << players[i].getName() << ", The Dealer got more than 21, you win!" << endl;

                int newMoneyTotal = (players[i].getBet() * 2) + players[i].getMoney();
                players[i].Money(newMoneyTotal);
            } else if (PlayerCardV[i] < dealerValue.front()) {

                cout << players[i].getName() << ", Sorry You Lost you have " << PlayerCardV[i] << " and the dealer has " << dealerValue.front() << endl;
                cout << "This means you lost" << endl;

            } else {

                // It's a tie
                cout << players[i].getName() << ", You tied. You have: " << PlayerCardV[i] << " and the dealer has " << dealerValue.front() << endl;
                int newMoneyTotal = players[i].getBet() + players[i].getMoney();
                players[i].Money(newMoneyTotal);

            }

        }

    }

    
    cout << endl << endl;
    cout << "THIS IS THE PLAYERS: " << endl;
    for(int i =0;i < Nplay;i++){
        if(players[i].getBet() >= 10){
            
            
            cout << players[i].getName() << " = $" << players[i].getMoney() << endl; 
            
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
