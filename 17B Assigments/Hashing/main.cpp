#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <unordered_map>
#include <algorithm>
#include <list>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

int linearSearch(const string arr[], int n, const string &target);
int binarySearch(const string arr[], int low, int high, const string &target);

// Declare alphanum globally
static const char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int TABLE_SIZE = 100000; // Size of the hash table

// Hash node structure for chaining

struct HashNode {
    string key;
    string value;
};

// Hash table with chaining

class HashTable {
private:
    list<HashNode> table[TABLE_SIZE]; // Array of linked lists

public:
    // Hash function using BKDRHash

    unsigned int hashFunction(const string& key) {
        unsigned int seed = 131;
        unsigned int hash = 0;

        for (size_t i = 0; i < key.length(); i++) {
            hash = (hash * seed) + key[i];
        }

        return hash % TABLE_SIZE; // Modulo to fit within the table size
    }

    // Insert a key-value pair into the hash table

    void insert(const string& key, const string& value) {
        unsigned int index = hashFunction(key);
        HashNode newNode = {key, value};
        table[index].push_back(newNode);
    }

    // Search for a key in the hash table

    string search(const string& key) {
        unsigned int index = hashFunction(key);
        int position = 0;

        for (const auto& node : table[index]) {
            if (node.key == key) {
                return "Value found in position " + to_string(index);
            }
            position++;
        }

        return "Value not found";
    }
    // Display the contents of the hash table

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Bucket " << i << ": ";
            for (const auto& node : table[i]) {
                cout << "(" << node.key << ", " << node.value << ") ";
            }
            cout << endl;
        }
    }
};

// Function to generate a random string of a given size
string generateRandomString(int size, mt19937 &gen, uniform_int_distribution<> &dis) {
    string random_string;

    for (int i = 0; i < size; ++i) {
        random_string += alphanum[dis(gen)];
    }

    return random_string;
}


int main() {
    HashTable h;
    int stringSize = 20; // size of the string
    int nSize = 500000;       // size of arrays

    string *searchArray = new string[nSize];
    string *linearSearchArray = new string[nSize];
    string *binarySearchArray = new string[nSize];

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, sizeof(alphanum) - 2);

    for (int i = 0; i < nSize; i++) {
        string random_string = generateRandomString(stringSize, gen, dis);

        if (i % 2 == 0) {
            searchArray[i] = random_string;
        } else {
            searchArray[i] = generateRandomString(stringSize, gen, dis);
        }

        linearSearchArray[i] = random_string;
        binarySearchArray[i] = random_string;
        h.insert(random_string,random_string);
    }

    shuffle(searchArray, searchArray + nSize, gen);

//    for (int i = 0; i < nSize; i++) {
//        cout << "Search = " << searchArray[i] << endl;
//
//        // Perform linear search
//        int linearIndex = linearSearch(linearSearchArray, nSize, searchArray[i]);
//        if (linearIndex != -1) {
//            cout << "Linear Search found at index: " << linearIndex << endl;
//        } else {
//            cout << "Linear Search not found." << endl;
//        }
//
//        // Sort binarySearchArray before performing binary search
//        sort(binarySearchArray, binarySearchArray + nSize);
//
//        // Perform binary search
//        int binaryIndex = binarySearch(binarySearchArray, 0, nSize - 1, searchArray[i]);
//        if (binaryIndex != -1) {
//            cout << "Binary Search found at index: " << binaryIndex << endl;
//        } else {
//            cout << "Binary Search not found." << endl;
//        }
//
//        // Hash function with chaining
////        h.display();
//        cout << h.search(searchArray[i]) << endl;
//
//        cout << endl;
//    }
    

    
//    //linear search timing 
//    auto startLinear = high_resolution_clock::now();
//    for (int i = 0; i < nSize; i++) {
//        int linearIndex = linearSearch(linearSearchArray, nSize, searchArray[i]);
//    }
//    auto stopLinear = high_resolution_clock::now();
//    auto durationLinear = duration_cast<milliseconds>(stopLinear - startLinear);
//    cout << "Linear Search took: " << durationLinear.count() << " milliseconds" << endl;

    // Sort binarySearchArray outside the loop
    sort(binarySearchArray, binarySearchArray + nSize);

    // Measure time for binary search
    auto startBinary = high_resolution_clock::now();
    for (int i = 0; i < nSize; i++) {
        int binaryIndex = binarySearch(binarySearchArray, 0, nSize - 1, searchArray[i]);
    }
    auto stopBinary = high_resolution_clock::now();
    auto durationBinary = duration_cast<milliseconds>(stopBinary - startBinary);
    cout << "Binary Search took: " << durationBinary.count() << " milliseconds" << endl;


    // Measure time for hash table search
    auto startHash = high_resolution_clock::now();
    for (int i = 0; i < nSize; i++) {
        h.search(searchArray[i]);
    }
    auto stopHash = high_resolution_clock::now();
    auto durationHash = duration_cast<milliseconds>(stopHash - startHash);
    cout << "Hash Table Search took: " << durationHash.count() << " milliseconds" << endl;
    
    delete[] searchArray;
    delete[] linearSearchArray;
    delete[] binarySearchArray;

    return 0;
}


// Linear search function
int linearSearch(const string arr[], int n, const string &target) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == target) {
            return i; // Target found, return the index
        }
    }
    return -1; // Target not found
}

// Binary search function
int binarySearch(const string arr[], int low, int high, const string &target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; // Target found, return the index
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // Target not found
}