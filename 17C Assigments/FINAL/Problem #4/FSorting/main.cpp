#include <iostream>
#include <algorithm>
#include <ctime>

void merge(int array[], int const left, int const mid, int const right);
void mergeSort(int array[], int const begin, int const end);
void selectSort(int array[], int size);

int Si,Sj,Sif;
int Moperatioal;

using namespace std;

int main() {
    const int size = 40000;
    int Nloop = 1000;
    int arr[size];

    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000;
    }


    int mergearr[size];
    copy(arr, arr + size, mergearr);
//    int beg = time(0);
//    for(int i=0;i<Nloop;i++){
        mergeSort(arr,0,size-1);
//    }
//    int end = time(0);
    cout << "Merge-sorted array: " << Moperatioal << " operations" << endl;
    cout << endl;

    
//    beg = 0;
//    end=0;
    int selectarr[size];
    copy(arr, arr + size, selectarr);
//    beg = time(0);
//    for(int i=0;i<Nloop;i++){
        selectSort(selectarr,size);
//    }
//    end = time(0);

    cout << "Select-sorted array: " << Si+Sj+Sif << " operations" << endl;;
    cout << endl;
    


    return 0;
}

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
    Moperatioal += 20;
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
    Moperatioal+=8;

    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    Moperatioal+=4;

    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    Moperatioal+=4;

    delete[] leftArray;
    delete[] rightArray;
    Moperatioal+=2;
}

void mergeSort(int array[], int const begin, int const end) {
    if (begin >= end)
        return;
    Moperatioal++;

    int mid = begin + (end - begin) / 2;
    Moperatioal+= 4;
    mergeSort(array, begin, mid);
    Moperatioal++;
    mergeSort(array, mid + 1, end);
    Moperatioal++;
    merge(array, begin, mid, end);
    Moperatioal++;
}

void selectSort(int arr[], int n) {
    for (int i = n - 1; i >= n-8; i--) {
        Si+=5;
        int maxIndex = i;
        Si+=2;
        for (int j = i - 1; j >= 0; j--) {
            Sj += 4;
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
                Sif+=2;
            }
        }

        // Swap the found maximum element with the element at index i
        swap(arr[maxIndex], arr[i]);
        Si++;

    }
}