/* 
 * Eduardo Murillo Palacio
 * 11/22/23
 * Bloom Filter
 *
 * Created on November 22, 2023, 12:27 AM
 */

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// hash 1

int h1(string s, int arrSize) {
    int hash = 0;
    for (int i = 0; i < s.size(); i++) {
        hash = (hash + ((int) s[i]));
        hash = hash % arrSize;
    }
    return hash;
}

// hash 2

int h2(string s, int arrSize) {
    int hash = 3;
    int p = 7;
    for (int i = 0; i < s.size(); i++) {
        hash += hash * 7 + s[0] * pow(p, i);
        hash = hash % arrSize;
    }
    return hash;
}

void insert(int bitarr[], int size, string s) {
    int hash1 = h1(s, size);
    int hash2 = h2(s, size);

    bitarr[hash1] = 1;
    bitarr[hash2] = 1;

    cout << s << " was inserted into " << hash1 << " and " << hash2 << endl;
}

void membership(int bitarr[], string s, int size) {
    int hash1 = h1(s, size);
    int hash2 = h2(s, size);

    if (bitarr[hash1] && bitarr[hash2]) {
        cout << " " << hash1 << " - " << hash2 << " ";
        cout << " = maybe" << endl;
    } else {
        cout << " = no" << endl;
    }
}

float pos(float m, float k, float n) {
    return pow((1 - pow((1 - (1 / m)), (k * n))), k) * 100;
}

int main() {
    int bitarray[14] = {0};
    float arrSize = 14;
    float numOfNames = 5;
    string arr[] = {"Justin", "Jose", "Eduardo", "Mark", "Dan"};

    cout << "Empty Bitarray" << endl;
    for (int i = 0; i < 14; i++) {
        cout << bitarray[i] << " - ";
    }
    cout << endl
            << endl;

    for (int i = 0; i < 5; i++) {
        insert(bitarray, arrSize, arr[i]);
    }

    for (int i = 0; i < 5; i++) {
        cout << "Inserted = " << arr[i] << endl;
    }
    cout << endl;

    cout << "Bitarray" << endl;
    for (int i = 0; i < 14; i++) {
        cout << bitarray[i] << " - ";
    }
    cout << endl
            << endl;

    cout << "Test for membership Eduardo";
    membership(bitarray, "Eduardo", arrSize);

    cout << "Test for membership David";
    membership(bitarray, "David", arrSize);

    cout << "Test for membership Juan";
    membership(bitarray, "Juan", arrSize);

    cout << "Test for membership Dan";
    membership(bitarray, "Dan", arrSize);

    cout << "Probability of a false positive: " << pos(arrSize, 2, numOfNames) << "%" << endl;

    return 0;
}
