#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int binSrch(int a[], int n, int val);

int main() {
    srand(static_cast<unsigned int>(time(0))); // Fixed the missing closing parenthesis
    
    const int SIZE = 500;
    int brray[SIZE];
    int lowRng = 100, highRng = 200;
    
    // Initialize the array brray with random values
    for (int i = 0; i < SIZE; i++) {
        brray[i] = rand() % (highRng - lowRng + 1) + lowRng;
    }
    
    int nsize = 100000000;
    int value = rand() % (highRng - lowRng + 1) + lowRng;
    
    float beg, end;
    
    beg = static_cast<float>(clock()) / CLOCKS_PER_SEC;
    cout << "Binary search : ";
    
    for (int i = 0; i < nsize; i++) {
        int result = binSrch(brray, SIZE, value);
        // You can print the result if needed, e.g., cout << result << " ";
    }
    
    end = static_cast<float>(clock()) / CLOCKS_PER_SEC;
    
    cout << "For N=" << SIZE << " Binary search Takes " << (end - beg) << " Seconds" << endl;
    
    return 0;
}

int binSrch(int a[], int n, int val) {
    int lowEnd = 0;
    int highEnd = n - 1;
    
    do {
        int middle = (highEnd + lowEnd) / 2;
        if (val == a[middle]) return middle;
        else if (val > a[middle]) lowEnd = middle + 1;
        else highEnd = middle - 1;
    } while (lowEnd <= highEnd);
    
    return -1;
}
