#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Clerk {
    int Services;
    int timeServices = 0;
};

void deleteElement(Clerk*& arr, int& size, int index);

int getRandomPercentage() {
    // Generates a random percentage in the range [-50, 50]
    return rand() % 101 - 50;
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    queue<int> C;
    int customerNumber = 0;
    int simTimeInSECS = 5000;  // Simulation time in seconds
    const int arrivalInterval = 15;  // Arrival interval in seconds (4 customers per minute)
    int initial = 3;
    int helpC = 0;
    int maxNumHelp = 0;
    Clerk* newClerk = nullptr;
    int y = simTimeInSECS / arrivalInterval;
    int* totalWaitTime = new int[y]{};

    Clerk clerks[3];
    clerks[0].Services = 60;
    clerks[1].Services = 120;
    clerks[2].Services = 80;

    for (int currentTime = 1; currentTime <= simTimeInSECS; currentTime++) {
        if (currentTime % arrivalInterval == 0) {
            C.push(customerNumber);
            totalWaitTime[customerNumber] = currentTime;  // Record the arrival time
            customerNumber++;
        }

        // Process existing clerks
        for (int i = 0; i < initial; i++) {
            if (clerks[i].timeServices > 0) {
                clerks[i].timeServices--;
            } else if (!C.empty()) {
                clerks[i].timeServices = clerks[i].Services + getRandomPercentage() * clerks[i].Services / 100;
                totalWaitTime[C.front()] -= currentTime;  // Subtract arrival time from current time
                C.pop();
            }
        }

        // Check if the queue has 5 or more customers
        if (C.size() >= 5) {
            // Add a new clerk
            if (helpC == 0) {
                newClerk = new Clerk[helpC + 1];
                newClerk[helpC].Services = 60 + getRandomPercentage() * 60 / 100;
                helpC++;
            } else {
                // Resize the array
                Clerk* temp = new Clerk[helpC + 1];
                for (int i = 0; i < helpC; i++) {
                    temp[i] = newClerk[i];  // Copy elements from the original array
                }
                delete[] newClerk;  // De-allocate the original array
                newClerk = temp;  // Update the pointer to the resized array

                // Add a new Clerk to the resized array
                newClerk[helpC].Services = 60 + getRandomPercentage() * 60 / 100;  // Initialize the newly added clerk
                helpC++;
            }
            if (maxNumHelp < helpC) {
                maxNumHelp = helpC;
            }
        }

        for (int i = 0; i < helpC; i++) {
            if (C.empty() && newClerk[i].timeServices == 0) {
                deleteElement(newClerk, helpC, i);
            }
            if (newClerk[i].timeServices > 0) {
                newClerk[i].timeServices--;
            } else if (!C.empty()) {
                newClerk[i].timeServices = newClerk[i].Services + getRandomPercentage() * newClerk[i].Services / 100;
                totalWaitTime[C.front()] -= currentTime;  // Subtract arrival time from current time
                C.pop();
            }
        }
    }

    // Calculate average wait time
    int Temp = 0;
    for (int i = 0; i < customerNumber; i++) {
        Temp += totalWaitTime[i];
    }
    double averageWaitTime = static_cast<double>(Temp) / customerNumber;
    cout << "Average Customer Wait Time: " << (averageWaitTime / 60) << " minutes" << endl;

    cout << "Maximum Number of Clerks: " << maxNumHelp << endl;
    cout << "Customers left in line: " << C.size() << endl;

    // Clean up memory
    delete[] newClerk;
    delete[] totalWaitTime;

    return 0;
}

void deleteElement(Clerk*& arr, int& size, int index) {
    if (index < 0 || index >= size) {
        std::cout << "Invalid index for deletion." << std::endl;
        return;
    }

    // Create a new array with one less element
    Clerk* newArr = new Clerk[size - 1];

    // Copy elements before the index
    for (int i = 0; i < index; ++i) {
        newArr[i] = arr[i];
    }

    // Copy elements after the index
    for (int i = index + 1; i < size; ++i) {
        newArr[i - 1] = arr[i];
    }

    // Deallocate the memory of the original array
    delete[] arr;

    // Update the array and size
    arr = newArr;
    --size;
}
