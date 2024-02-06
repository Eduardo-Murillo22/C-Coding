// C++ implementation of Shell Sort 

//code from: https://www.geeksforgeeks.org/shellsort/

#include  <iostream> 
#include  <ctime> 

using namespace std; 
  
/* function to sort arr using shellSort */
int shellSort(int arr[], int n) 
{ 
    // Start with a big gap, then reduce the gap 
    for (int gap = n/2; gap > 0; gap /= 2) 
    { 
        // Do a gapped insertion sort for this gap size. 
        // The first gap elements a[0..gap-1] are already in gapped order 
        // keep adding one more element until the entire array is 
        // gap sorted  
        for (int i = gap; i < n; i += 1) 
        { 
            // add a[i] to the elements that have been gap sorted 
            // save a[i] in temp and make a hole at position i 
            int temp = arr[i]; 
  
            // shift earlier gap-sorted elements up until the correct  
            // location for a[i] is found 
            int j;             
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
                arr[j] = arr[j - gap]; 
              
            //  put temp (the original a[i]) in its correct location 
            arr[j] = temp; 
        } 
    } 
    return 0; 
} 
  
void printArray(int arr[], int n) 
{ 
    for (int i=0; i<n; i++) 
        cout << arr[i] << " "; 
}


int main(int argc, char** argv) {
    int SIZE = 13000;
    int* arr = new int[SIZE];


    int beg = time(0);
    for(int i=0;i<10000;i++){
        shellSort(arr, SIZE);   
    }
    int totTime = time(0) - beg;
    cout << "Total run time = " << totTime << endl;

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