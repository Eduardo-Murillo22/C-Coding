
/* 
 * File:   main.cpp
 * Author: Eduardo Murillo
 *
 * Created on November 7, 2023, 6:45 PM
 */

#include <iostream>
#include <ctime>

using namespace std;

void flipCoin(int &head, int &tail);
void flipCoinBias(int &head, int &tail);

/*
 * 
 */
int main(int argc, char** argv) {

    
    srand(static_cast<unsigned>(std::time(nullptr)));
    float results = 0;
    int trails=10000;

    //for 50/50 coin
    cout << "calculate the probability of flipping a coin 4 times and getting 1 tail and 3 heads." << endl;
    for (int i = 0; i < trails; i++) { 
        int head = 0, tail = 0;
        flipCoin(head, tail);
        if(head == 3 && tail == 1){
            results++;
        }

    }
    float answers = results/trails;
    cout << "For n = trails " << trails << " and number of outcomes " << results << " = " << answers << " or " << answers*100 << "%" << endl;
    cout << endl;
    
    //for bias coin
    cout << "What if you had a biased coin that would come up heads 60% of the time." << endl;
    float resultBias = 0;
    for (int i = 0; i < trails; i++) { 
        int head = 0, tail = 0;
        flipCoinBias(head, tail);
        if(head == 3 && tail == 1){
            resultBias++;
        }

    }
    float answersBias = resultBias/trails;
    cout << "For n = trails for a 60% head bias coin " << trails << " and number of outcomes " << resultBias << " = " << answersBias << " or " << answersBias*100 << "%" << endl;
    
    
    
    return 0;
}


void flipCoin(int &head, int &tail){
    for(int i = 0;i < 4;i++){
        int result = rand() % 2;
        if (result == 0) {
            head++;
        } else {
            tail++;
        }
    }
}

void flipCoinBias(int &head, int &tail){
    for(int i = 0;i < 4;i++){
        int result = (rand() % 100) < 60 ? 0 : 1;
        if (result == 0) {
            head++;
        } else {
            tail++;
        }
    }
}