#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>
#include <list>

using namespace std;

static const char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int hashTableSize = 10;

int linearSearch(const string arr[], int n, const string &target);
int binarySearch(const string arr[], int low, int high, const string &target);
string generateRandomString(int size, mt19937 &gen, uniform_int_distribution<> &dis);

class Hash {
private:
    list<string> hashTable[hashTableSize];

public:
    // Insert a key into the hash table

    void InsertHash(const string &key) {
        // Calculate hash
        unsigned int hash = HashFunction(key);

        // Insert into the linked list at the hashed index
        hashTable[hash].push_back(key);
    }

    // Custom hash function

    unsigned int HashFunction(const string &str) {
        unsigned int hash = 0;
        for (char c : str) {
            hash += static_cast<unsigned int> (c);
        }
        return hash % hashTableSize;
    }

    // Display the hash table

    void DisplayHash() {
        for (int i = 0; i < hashTableSize; ++i) {
            cout << "Bucket " << i << ": ";
            for (const string &key : hashTable[i]) {
                cout << key << " -> ";
            }
            cout << "NULL" << endl;
        }
    }

    // Search for a key in the hash table

    bool SearchHash(const string &key, int &index, int &position) {
        // Calculate hash
        unsigned int hash = HashFunction(key);

        // Search for the key in the linked list at the hashed index
        auto it = find(hashTable[hash].begin(), hashTable[hash].end(), key);
        if (it != hashTable[hash].end()) {
            // Key found, calculate index and position
            index = hash;
            position = distance(hashTable[hash].begin(), it);
            return true;
        }
        return false; // Key not found
    }
    
};


int main()
{
    Hash hashTable;
    int stringSize = 20; // size of the string
    int nSize = 200000;      // size of arrays

    string *searchArray = new string[nSize];
    string *linearSearchArray = new string[nSize];
    string *binarySearchArray = new string[nSize];

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, sizeof(alphanum) - 2);

    for (int i = 0; i < nSize; i++)
    {
        string random_string = generateRandomString(stringSize, gen, dis);

        if (i % 2 == 0)
        {
            searchArray[i] = random_string;
        }
        else
        {
            searchArray[i] = generateRandomString(stringSize, gen, dis);
        }

        linearSearchArray[i] = random_string;
        binarySearchArray[i] = random_string;
        hashTable.InsertHash(random_string);
    }

    shuffle(searchArray, searchArray + nSize, gen);

//    int beg = time(0);
//    cout << "Linear search : ";
//    for (int i = 0; i < nSize; i++) {
//        linearSearch(linearSearchArray,nSize,searchArray[i]);
//    }
//    int end = time(0);
//    cout << "For N=" << nSize << " Linear search Takes "
//            << end - beg << " Seconds" << endl;
//    cout << endl << endl;
    
    sort(binarySearchArray, binarySearchArray + nSize);

    int beg = time(0);
    cout << "Binary search : ";
    for (int i = 0; i < nSize; i++) {
        binarySearch(binarySearchArray,0,nSize-1,searchArray[i]);
    }
    int end = time(0);
    cout << "For N=" << nSize << " Binary search Takes "
            << end - beg << " Seconds" << endl;
    cout << endl << endl;
    

     beg = time(0);
    cout << "Hashing search : ";
        for(int i=0;i < nSize;i++){
            int Index = 0;
            int Position = 0;
            hashTable.SearchHash(searchArray[i], Index, Position);
        }
     end = time(0);
    cout << "For N=" << nSize << " Hashing search Takes "
            << end - beg << " Seconds" << endl;
    cout << endl << endl;

    // Free the memory allocated for arrays
    delete[] searchArray;
    delete[] linearSearchArray;
    delete[] binarySearchArray;

    return 0;
}

// Function to generate a random string of a given size
string generateRandomString(int size, mt19937 &gen, uniform_int_distribution<> &dis)
{
    string random_string;

    for (int i = 0; i < size; ++i)
    {
        random_string += alphanum[dis(gen)];
    }

    return random_string;
}

int linearSearch(const string arr[], int n, const string &target)
{
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == target)
        {
            return i; // Target found, return the index
        }
    }
    return -1; // Target not found
}

int binarySearch(const string arr[], int low, int high, const string &target)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            return mid; // Target found, return the index
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1; // Target not found
}
