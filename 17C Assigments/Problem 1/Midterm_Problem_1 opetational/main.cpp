/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Purpose:  Common searching and sorting algorithms
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void prntAry(const int [],int,int);
void fillAry(int [],int,int,int);
void swap(int &,int &);
void smlLst(int [],int,int);
void mrkSort(int [],int);
int  linSrch(int [],int, int);
int  binSrch(int [],int, int);
void bublSrt(int [],int);
void selSort(int [],int);
void copyAry(int [],int [],int);

//operations for binary
int ObB,OdoB,PosB;
//operations for linear
int Ob,Oi,Pos;


//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    const int SIZE=800;
    int array[SIZE],brray[SIZE];
    int lowRng=100,highRng=200;
    int perLine=10;
        
    //Finish initializing the rest of the array
    fillAry(array,SIZE,highRng,lowRng);
    copyAry(brray,array,SIZE);
       
    //Sort the array the for all positions
    //mrkSort(array,SIZE);
    bublSrt(array,SIZE);
    selSort(brray,SIZE);
    
    int value = rand() % (highRng - lowRng + 1) + lowRng;
    
    binSrch(brray,SIZE,value);
    
    cout << "Operations for binary search before the do loop for size n = " << SIZE << " = " << ObB << endl;
    cout << "Operations for binary search in the the do loop for size n = " << SIZE << " = " << OdoB << endl;
    cout << "Operations for binary search is statements for size n      = " << SIZE << " = " << PosB << endl;
    cout << "Total operations = " << ObB + OdoB + PosB << endl << endl << endl;

    
    linSrch(array,SIZE,value);
    
    cout << "Operations for linear search before the loop for size " << SIZE << " = " << Ob  << endl;
    cout << "Operations for linear search in I the loop for size " << SIZE << "   = " << Oi  << endl;
    cout << "Operations for linear search in if statement for size " << SIZE << " = "  << Pos << endl;
    cout << "Total Amount of operations = " << Ob+Oi+Pos << endl;

    
    
    
    //Exit
    return 0;
}

void copyAry(int copyIt[],int source[],int n){
    for(int i=0;i<n;i++){
        copyIt[i]=source[i];
    }
}

void selSort(int a[],int n){
    //Loop and declare variables
    int indx,min;
    for(int pos=0;pos<n-1;pos++){
        //Find the smallest in the list, swap after finding
        min=a[pos];
        indx=pos;
        for(int i=pos+1;i<n;i++){
            if(a[i]<min){
                min=a[i];
                indx=i;
            }
        }
        //Perform the swap
        a[indx]=a[pos];
        a[pos]=min;
    }
}

void bublSrt(int a[],int n){
    //Keep looping and comparing until no swaps are left
    bool swap;
    do{
        swap=false;
        //Check the list and Swap when necessary
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                swap=true;
            }
        }
    }while(swap);
}

int  binSrch(int a[],int n, int val){
    //Initialize end points which are indexes
    int lowEnd=0;
    int highEnd=n-1;
    ObB+=5;
    //Loop until value found not indexes
    do{
        OdoB+=6;
        int middle=(highEnd+lowEnd)/2;
        if(val==a[middle]){
            PosB += 1;
            return middle;
        }
        else if(val>a[middle]){
            OdoB += 2;
            PosB += 2;
            lowEnd=middle+1;
        }
        else {
            OdoB += 2;
            PosB += 2;
            highEnd=middle-1;
        }
        
    }while(lowEnd<=highEnd);
    
    //Not found
    return -1;
}

int  linSrch(int a[],int n, int val){
    Ob++;
    for(int indx=0;indx<n;indx++){
        Oi+=2;
        if(val==a[indx]){
            Pos++;
            return indx;
        }
    }
    return -1;
}

void fillAry(int a[],int n,int hr,int lr){
    for(int indx=0;indx<n;indx++){
        a[indx]=rand()%(hr-lr+1)+lr;
    }
}

void prntAry(const int a[],int n,int perLine){
    //Print the values in the array
    cout<<endl<<"The Array Values"<<endl;
    for(int indx=0;indx<n;indx++){
        cout<<a[indx]<<" ";
        if(indx%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void mrkSort(int a[],int n){
    for(int pos=0;pos<n-1;pos++){
        smlLst(a,n,pos);
    }
}

void smlLst(int a[],int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(a[pos]>a[i]){
            swap(a[pos],a[i]);
        }
    }
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}