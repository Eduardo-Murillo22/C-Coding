#include <iostream>
#include <chrono>
#include <algorithm>  // For copy and swap
#include <cstdlib>

// Function declarations
void mergeSort(int arr[], int left, int right);
void selectSort(int arr[], int size, int p);

using namespace std;

int main() {
    const int size = 100000;
//    int Nloop = 1000;
    int arr[size];
    int p = 70;
    int secSelect = 0, secMerge = 0;

    srand(static_cast<unsigned> (time(0)));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000;
    }

    while (secSelect <= secMerge) {
        cout << "p = " << p << endl;
        int mergearr[size];
        copy(arr, arr + size, mergearr);
        auto beg = chrono::high_resolution_clock::now();
//        for (int i = 0; i < Nloop; i++) {
            mergeSort(mergearr, 0, size - 1);
//        }
        auto end = chrono::high_resolution_clock::now();
        secMerge = chrono::duration_cast<chrono::milliseconds>(end - beg).count();
        cout << "Merge sort: " << secMerge << " milliseconds" << endl;

        beg = chrono::high_resolution_clock::now();
        int selectarr[size];
        copy(arr, arr + size, selectarr);
//        for (int i = 0; i < Nloop; i++) {
            selectSort(selectarr, size, p);
//        }
        end = chrono::high_resolution_clock::now();
        secSelect = chrono::duration_cast<chrono::milliseconds>(end - beg).count();
        cout << "Select sort: " << secSelect << " milliseconds" << endl;
        cout << endl;
        p++;
    }

    cout << "Point where merge sort wins = " << p-1 << endl;

    return 0;
}

// Implementation of mergeSort and selectSort functions goes here


void merge(int array[], int const left, int const mid, int const right) {
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    auto *leftArray = new int[subArrayOne];
    auto *rightArray = new int[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        } else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int array[], int const begin, int const end) {
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void selectSort(int arr[], int n,int p) {
    for (int i = n - 1; i >= n-p; i--) {
        int maxIndex = i;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }

        // Swap the found maximum element with the element at index i
        swap(arr[maxIndex], arr[i]);

    }
}