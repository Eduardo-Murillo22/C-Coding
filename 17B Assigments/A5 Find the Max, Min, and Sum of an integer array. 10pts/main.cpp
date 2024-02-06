/* 
 * File:   main.cpp
 * Author: YOUR NAME HERE
 * Created on DATE AND TIME HERE
 * Purpose:  Summing, Finding the Max and Min of an integer array
 * Note:  Look at the output for the format for print
 */

//System Libraries Here
#include <iostream>//cin,cout
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables

//Function Prototypes Here
void read(int [],int);
int  stat(const int [],int,int &,int &);
void print(const int [],int,int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;
    int array[SIZE];
    int sizeIn,sum,min,max;
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of integers find sum/min/max"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of integers
    cout<<"Now read the Array"<<endl;
    read(array,sizeIn);//Read in the array of integers
    
    //Find the sum, max, and min
    sum=stat(array,sizeIn,max,min);//Output the sum, max and min
    
    //Print the results
    print(array,sizeIn,sum,max,min);//print the array, sum, max and min

    //Exit
    return 0;
}

void read(int intarr[],int size)
{
    for(int x=0;x < size; x++ )
    {
        cin >> intarr[x];
    }
    
}

int  stat(const int intarr[],int size,int &max,int &min)
{
    int sum=0;
    for(int x=0;x < size; x++ )
    {
        sum=+intarr[x];
        int* ptrMax = &max;
        int* ptrMin = &min;
        
        if(intarr[x] > *ptrMax)
        {
            *ptrMin = intarr[x];
        }
        if(intarr[x] < *ptrMin )
        {
            *ptrMin = intarr[x];
        }
        
    }
    return sum;
    
}

void print(const int intarr[],int size,int sum,int max,int min)
{    
    for(int x=0;x < size; x++ )
    {
        cout << intarr[x] << endl;
    }
    cout << endl;
    cout << "Max\n";
    cout << max << endl;
    cout << "min\n";
    cout << min << endl;
    cout << "sum\n";
    cout << sum;


}