#include <iostream>
#include <vector>
#include <random>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int num_simulations = 1000000; // Number of simulations

    int total_face_values = 13;
    int cards_per_face_value = 4;
    int cards_to_draw = 4;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(1, total_face_values);

    map<string, int> results;
    

    for (int i = 0; i < num_simulations; ++i) {
        vector<int> deck;

        // Initialize the deck
        for (int face_value = 1; face_value <= total_face_values; ++face_value) {
            for (int j = 0; j < cards_per_face_value; ++j) {
                deck.push_back(face_value);
            }
        }

        // Shuffle the deck
        shuffle(deck.begin(), deck.end(), gen);

        // Draw 4 cards
        vector<int> hand;
        for (int j = 0; j < cards_to_draw; ++j) {
            hand.push_back(deck[j]);
        }



        // Count the occurrences of each face value in the hand
        map<int, int> face_value_counts;
        for (int card : hand) {
            face_value_counts[card]++;
        }

        // Check for poker hand scenarios
        bool one_pair = false;
        bool two_pair = false;
        bool three_of_a_kind = false;
        bool four_of_a_kind = false;

        for (const auto& pair : face_value_counts) {
            int count = pair.second;
            if (count == 2) {
                if (one_pair) {
                    two_pair = true;
                } else {
                    one_pair = true;
                }
            } else if (count == 3) {
                three_of_a_kind = true;
            } else if (count == 4) {
                four_of_a_kind = true;
            }
        }

        if (four_of_a_kind) {
            results["Four of a Kind"]++;
        } else if (three_of_a_kind) {
            results["Three of a Kind"]++;
        } else if (two_pair) {
            results["Two Pair"]++;
        } else if (one_pair) {
            results["One Pair"]++;
        }
    }

    // Calculate and print the simulated probabilities
    cout << "Simulated Probabilities:" << endl;
    for (const auto& pair : results) {
        double probability = static_cast<double>(pair.second) / num_simulations;
        cout << pair.first << ": " << probability << endl;
    }


    return 0;
}
