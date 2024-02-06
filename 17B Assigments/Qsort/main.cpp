// C++ Implementation of the Quick Sort Algorithm.

//code from: https://www.geeksforgeeks.org/cpp-program-for-quicksort/

#include <iostream>
#include <ctime>
using namespace std;

void fillArray(int [],int);
 
int partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSort(int arr[], int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);
}
 
int main(int argc, char** argv)
{
    int SIZE = 13000;
    int* arr = new int[SIZE];

    int beg = time(0);
    for(int i=0; i < 100;i++){
    quickSort(arr, 0, SIZE - 1);
    }
    int totTime = time(0) - beg;
    cout << "Total run time = " <<  totTime << endl;
    
    delete[] arr;
    
    return 0;
}

// Implementation of the fillArray function

void fillArray(int arr[], int size) {
    // Seed for random number generation
    srand(time(0));

    // Fill the array with random values
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100; // Generates random values between 0 and 99
    }
}