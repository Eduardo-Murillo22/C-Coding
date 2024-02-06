#include <iostream>
#include <map>
#include <list>
#include <random>
#include <algorithm>

using namespace std;

int hashing(const string &IN) {
    int val = 0;
    map<string, int> LtoN{
        {"A", 2}, {"B", 2}, {"C", 2},
        {"D", 3}, {"E", 3}, {"F", 3},
        {"G", 4}, {"H", 4}, {"I", 4},
        {"J", 5}, {"K", 5}, {"L", 5},
        {"M", 6}, {"N", 6}, {"O", 6},
        {"P", 7}, {"Q", 7}, {"R", 7}, {"S", 7},
        {"T", 8}, {"U", 8}, {"V", 8},
        {"W", 9}, {"X", 9}, {"Y", 9}, {"Z", 9}};

    for (int i = 0; i < IN.size(); i++) {
        map<string, int>::iterator it = LtoN.begin();

        while (it != LtoN.end()) {
            if (toupper(IN[i]) == (it->first)[0]) {
                val = val * 10 + it->second;
            }
            ++it;
        }
    }
    return val % 512;
}

string generateRandomInitials(mt19937 &rng) {
    string initials;

    uniform_int_distribution<int> distribution('A', 'Z');
    for (int i = 0; i < 3; ++i) {
        char randomLetter = static_cast<char>(distribution(rng));
        initials += randomLetter;
    }

    return initials;
}

void deleteElement(list<int> *&arr, int &size, int index);

int main() {
    int size = 512;
    list<int> *linkedListArray = new list<int>[size];

    mt19937 rng(random_device{}());

    for (int i = 0; i < size; i++) {
        string Initials = generateRandomInitials(rng);
        int num = hashing(Initials);
        linkedListArray[num].push_back(i);
    }

    int numCollisions = 0;

    // Count the number of slots with collisions
    for (int i = 0; i < size; ++i) {
        if (linkedListArray[i].size() > 1) {
            numCollisions++;
        }
    }

    double collisionProbability = static_cast<double>(numCollisions) / size;

    cout << "Collision Probability: " << collisionProbability << endl;

    int max = 0;
    int elem[10] = {0};

    // Count the number of elements in each slot
    for (int i = 0; i < size; ++i) {
        if (linkedListArray[i].size() > max)
        {
            max = linkedListArray[i].size();
        }
        elem[linkedListArray[i].size()] += 1; //count how many times 1 appears etc.
    }

    for (int i = 0; i < 10; i++)
    {
        cout << "Number of times " << i << " appears: " << elem[i] << endl;
    }
    cout << "The  maximum number of collisions is: " << max << endl;

    // Clean up memory
    delete[] linkedListArray;

    return 0;
}