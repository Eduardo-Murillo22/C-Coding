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

struct node
{
    string data;
    node *next;
};

class Hash
{
private:
    node *table[hashTableSize];

public:
    Hash()
    {
        // Initialize each index with a null pointer
        for (int i = 0; i < hashTableSize; ++i)
        {
            table[i] = nullptr;
        }
    }

    void InsertHash(const string &key)
    {
        int index = HashFunction(key);

        // Create a new node
        node *newNode = new node{key, nullptr};

        if (table[index] == nullptr)
        {
            // If the list is empty, set the new node as the head
            table[index] = newNode;
        }
        else
        {
            // If the list is not empty, traverse to the end and append the new node
            node *current = table[index];
            while (current->next != nullptr)
            {
                current = current->next;
            }

            current->next = newNode;
        }
    }

    unsigned int HashFunction(const string &str)
    {
        unsigned int hash = 5381;

        for (size_t i = 0; i < str.length(); i++)
        {
            hash = ((hash << 5) + hash) + str[i];
        }

        return hash % hashTableSize;
    }

    void DisplayHash()
    {
        for (int i = 0; i < hashTableSize; ++i)
        {
            cout << "Index " << i << ": ";

            // Traverse the linked list at the current index
            node *current = table[i];
            while (current != nullptr)
            {
                cout << current->data << " ";
                current = current->next;
            }

            cout << endl;
        }
    }

    bool SearchHash(const string &key, int &index,int &position)
    {
        index = HashFunction(key);

        // Traverse the linked list at the calculated index
        node *current = table[index];

        while (current != nullptr)
        {
            if (current->data == key)
            {
                // Key found, return the index
                return true;
            }

            current = current->next;
            ++position;
        }

        // Key not found
        return false;
    }

    ~Hash()
    {
        // Free the allocated memory for each linked list
        for (int i = 0; i < hashTableSize; ++i)
        {
            node *current = table[i];
            while (current != nullptr)
            {
                node *temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
};

int main()
{
    Hash hashTable;
    int stringSize = 20; // size of the string
    int nSize = 20000;      // size of arrays

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

    int beg = time(0);
    cout << "Linear search : ";
    for (int i = 0; i < nSize; i++) {
        linearSearch(linearSearchArray,nSize,searchArray[i]);
    }
    int end = time(0);
    cout << "For N=" << nSize << " Linear search Takes "
            << end - beg << " Seconds" << endl;
    cout << endl << endl;
    
//    sort(binarySearchArray, binarySearchArray + nSize);
//
//    int beg = time(0);
//    cout << "Binary search : ";
//    for (int i = 0; i < nSize; i++) {
//        binarySearch(binarySearchArray,0,nSize-1,searchArray[i]);
//    }
//    int end = time(0);
//    cout << "For N=" << nSize << " Binary search Takes "
//            << end - beg << " Seconds" << endl;
//    cout << endl << endl;
    

//    int beg = time(0);
//    cout << "Hashing search : ";
//    for(int i=0;i < nSize;i++){
//        int Index = 0;
//        int Position = 0;
//        hashTable.SearchHash(searchArray[i], Index, Position);
//    }
//    int end = time(0);
//    cout << "For N=" << nSize << " Hashing search Takes "
//            << end - beg << " Seconds" << endl;
//    cout << endl << endl;
    
    

//    // Perform searches or other operations with the hash table as needed
//    for (int i = 0; i < nSize; i++)
//    {
//        int Index = 0;
//        int Position = 0;
//        bool found = hashTable.SearchHash(searchArray[i], Index, Position);
//
//        cout << "Searching for " << searchArray[i] << ": ";
//        if (!found)
//        {
//            cout << "Not found." << endl;
//        }
//        else
//        {
//            cout << "Found in Index #" << Index << " and Position -> " << Position << endl;
//        }
//    }

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
