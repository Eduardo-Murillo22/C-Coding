#include <iostream>
#include <algorithm>
#include <ctime>
#include <random>

using namespace std;

void shuffle(int[], int, mt19937&);

int main() {
    int numCards = 52,numSim = 1000000;
    int deck[numCards];
    float four = 0, three = 0, two = 0, one = 0;

    int index = 0;
    for (int number = 1; number <= 4; number++) {
        for (int suit = 1; suit <= 13; suit++) {
            deck[index++] = suit;
        }
    }

    unsigned seed = static_cast<unsigned>(time(nullptr));
    mt19937 gen(seed); // Random number generator
    //to use mt19937 with #inlude<random> research done from https://www.geeksforgeeks.org/stdmt19937-class-in-cpp/#


    for (int i = 0; i < numSim; i++) {
        shuffle(deck, numCards, gen);

        // Check the poker hand for the first 4 cards in the shuffled deck
        vector<int> hand(deck, deck + 4);

        bool onePair = false;

        // Count the occurrences of each face value in the hand
        int faceValueCounts[14] = {0}; // Face values range from 1 to 13

        for (int i = 0; i < 4; i++) {
            int faceValue = hand[i];
            faceValueCounts[faceValue]++;
        }

        for (int count : faceValueCounts) {
            if (count == 2) {
                if (onePair) {
                    two++;
                } else {
                    onePair = true;
                    one++;
                }
            } else if (count == 3) {
                three++;
            } else if (count == 4) {
                four++;
            }
        }
    }
    cout << "Number of One Pair: " << one / numSim * 100 << "%" << endl;
    cout << "Number of Two Pairs: " << two / numSim * 100 << "%" << endl;
    cout << "Number of Three of a Kind: " << three / numSim * 100 << "%" << endl;
    cout << "Number of Four of a Kind: " << four / numSim * 100 << "%" << endl;

    return 0;
}

void shuffle(int arr[], int size, mt19937& gen) {
    uniform_int_distribution<int> distribution(0, size - 1);

    for (int i = size - 1; i > 0; i--) {
        int j = distribution(gen);
        swap(arr[i], arr[j]);
    }
}
