/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 */

/*Problem 12) Code the mode problem first with the Set container, then use the Map container from the
STL. I have already coded the problem for you without those containers. You are to take my code and
reduce the number of lines required for the mode function by showing your expertise of Sets first then
using Maps second. The idea is that Sets should reduce the code required and Maps should reduce it
even further. Implement the function in the least amount of code for each container.*/

//Libraries
#include <cstdlib>//Random number seed
#include <ctime>//Set the seed
#include <iostream>//I/O
#include <set>//set
#include <map>
using namespace std;

//No Global Constants

//Function Prototypes
int *fillAry(int,int);
void prntAry(int *,int,int);
void prntMod(int *);
void swap(int *,int *);
void minPos(int *,int,int);
void mrkSort(int *,int);
int *copy(const int *,int);

int *modeSet(const int *,int);
int *modeMap(const int *,int);
int *mode(const int *,int);

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables and fill
    int arySize=30;
    int modNum=10;
    int *ary=fillAry(arySize,modNum);
    
    //Print the initial array
    prntAry(ary,arySize,10);
    
    //Calculate the mode array
    int *modeAry=mode(ary,arySize);
    //Print the modal information of the array
    cout << "\nUsing Arrays";
    prntMod(modeAry);

    //Calculate the mode array
    modeSet(ary, arySize);
    //Print the modal information of the array
    cout << "\nUsing Sets";
    prntMod(modeAry);

    //Calculate the mode array
    modeMap(ary, arySize);
    //Print the modal information of the array
    cout << "\nUsing Sets";
    prntMod(modeAry);
    
    //Delete allocated memory
    delete []ary;
    delete []modeAry;
    
    //Exit stage right
    return 0;
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

int *mode(const int *array,int arySize){//using arrays
    //Copy the array
    int *ary=copy(array,arySize);
    //Sort the ary
    mrkSort(ary,arySize);
    //Sort the copy
    //Find the max Freq
    int count=0,maxFreq=0;
    for(int i=0;i<arySize-1;i++){
        if(ary[i]==ary[i+1]){
            count++;
            if(maxFreq<count)maxFreq=count;
        }else{
            count=0;
        }
    }
    //Find the number of modes
    count=0;
    int nModes=0;
    for(int i=0;i<arySize-1;i++){
        if(ary[i]==ary[i+1]){
            count++;
            if(maxFreq==count)nModes++;
        }else{
            count=0;
        }
    }
    //Allocate the mode array
    int *modeAry=new int[nModes+2];
    //Fill the mode array
    modeAry[0]=nModes;
    modeAry[1]=maxFreq+1;
    count=0;
    int indx=2;
    for(int i=0;i<arySize-1;i++){
        if(ary[i]==ary[i+1]){
            count++;
            if(maxFreq==count)modeAry[indx++]=ary[i];
        }else{
            count=0;
        }
    }
    //Delete the allocated copy and return
    delete []ary;
    return modeAry;
}

int* modeSet(const int* array, int arySize) {
    std::set<int> mySet(array, array + arySize);

    int maxFreq = 0;
    int nModes = 0;

    for (int element : mySet) {
        int freq = 0;
        for (int i = 0; i < arySize; i++) {
            if (array[i] == element) {
                freq++;
            }
        }

        if (freq > maxFreq) {
            maxFreq = freq;
            nModes = 1;
        } else if (freq == maxFreq) {
            nModes++;
        }
    }

    int* modeAry = new int[nModes + 2];
    modeAry[0] = nModes;
    modeAry[1] = maxFreq;

    int indx = 2;
    for (int element : mySet) {
        int freq = 0;
        for (int i = 0; i < arySize; i++) {
            if (array[i] == element) {
                freq++;
            }
        }

        if (freq == maxFreq) {
            modeAry[indx++] = element;
        }
    }

    return modeAry;
}

int* modeMap(const int* array, int arySize) {
    std::map<int, int> frequencyMap;

    // Count the frequency of each element in the array
    for (int i = 0; i < arySize; i++) {
        frequencyMap[array[i]]++;
    }

    int maxFreq = 0;
    int nModes = 0;

    for (const auto& pair : frequencyMap) {
        int freq = pair.second;
        if (freq > maxFreq) {
            maxFreq = freq;
            nModes = 1;
        } else if (freq == maxFreq) {
            nModes++;
        }
    }

    int* modeAry = new int[nModes + 2];
    modeAry[0] = nModes;
    modeAry[1] = maxFreq;

    int indx = 2;

    for (const auto& pair : frequencyMap) {
        int freq = pair.second;
        if (freq == maxFreq) {
            modeAry[indx++] = pair.first;
        }
    }

    return modeAry;
}

void prntMod(int *ary){
    cout<<endl;
    cout<<"The number of modes = "<<
            ary[0]<<endl;
    cout<<"The max Frequency = "<<
            ary[1]<<endl;
    if(ary[0]==0){
        cout<<"The mode set = {null}"<<endl;
        return;
    }
    cout<<"The mode set = {";
    for(int i=2;i<ary[0]+1;i++){
        cout<<ary[i]<<",";
    }
    cout<<ary[ary[0]+1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        minPos(array,n,i);
    }
}

void minPos(int *array,int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(*(array+pos)>*(array+i))
            swap(array+pos,array+i);
    }
}

void swap(int *a,int *b){
    //Swap in place
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}

void prntAry(int *array,int n,int perLine){
    //Output the array
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<*(array+i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *fillAry(int n, int modNum){
    //Allocate memory
    int *array=new int[n];
    
    //Fill the array with 2 digit numbers
    for(int i=0;i<n;i++){
        *(array+i)=i%modNum;
        //*(array+i)=rand()%modNum;
    }
    
    //Exit function
    return array;
}