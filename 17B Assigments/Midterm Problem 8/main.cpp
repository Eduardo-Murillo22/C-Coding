#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int main() {
    // Probability of a single bit being within the filled section
    double p = 0.4;

    // Number of trials
    int n = 5;

    // Number of simulations
    int num_simulations = 1000000;

    // Initialize a random number generator
    unsigned seed = static_cast<unsigned> (time(nullptr));
    mt19937 gen(seed);
    //to use mt19937 with #inlude<random> research done from https://www.geeksforgeeks.org/stdmt19937-class-in-cpp/#
    
    uniform_real_distribution<double> distribution(0.0, 1.0);

    // Initialize a counter for successful outcomes
    float success_count = 0;

    for (int i = 0; i < num_simulations; i++) {
        // Simulate random selection of 5 bits
        bool all_bits_within_filled_section = true;
        for (int j = 0; j < n; j++) {
            double random_value = distribution(gen);
            if (random_value >= p) {
                all_bits_within_filled_section = false;
                break;
            }
        }

        // Check if all 5 bits are within the filled section
        if (all_bits_within_filled_section) {
            success_count++;
        }
    }

    // Calculate empirical probability
    float prob = success_count/num_simulations;
    cout << "Simulated Probability: " << prob << endl;

    return 0;
}
