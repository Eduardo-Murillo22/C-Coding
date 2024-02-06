/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 16, 2020, 7:50 PM
 * Purpose:  To Test and Modify the Simple Vector
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "SimpleVector.h"

//Global Constants

//Function prototypes
void fillVec(SimpleVector<char> &);
void prntVec(SimpleVector<char> &,int,int);
Link *fillLst(SimpleVector<char> &,int);
void prntLst(Link *,int,int);
void destroy(Link *);
SimpleVector<char> pshFrnt(SimpleVector<char> &,int &, char );
SimpleVector<char> pshBack(SimpleVector<char> &sv, int &size, char value);
void popFrnt(SimpleVector<char> &sv, int &size);
void popBack(SimpleVector<char> &sv, int &size);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int size=100;
    SimpleVector<char> sv(size);
    
    //Fill the Vector
    cout << "Normal simple vector.";
    fillVec(sv);
    //Print the Vector
    prntVec(sv,10,size);
    
    
    cout << "Add Y to the end" ;
    SimpleVector<char> temp1 = pshBack(sv, size, 'Y');
    sv = temp1;
    prntVec(sv, 10, size);
    cout << endl;
    
    
    cout << "Add X to the front";
    SimpleVector<char> temp = pshFrnt(sv,size,'X');
    sv = temp;
    prntVec(sv,10,size);
    cout << endl;
    
    cout << "popFront the X we put on previously in the front" << endl;
    popFrnt(sv,size);
    prntVec(sv,10,size);
    cout << endl;
    
    cout << "popBack the Y we put on previously in the back" << endl;
    popBack(sv,size);
    prntVec(sv,10,size);
    cout << endl;
    
    //Copy the Vector
    cout << "Simple vector data using linked list." << endl;
    Link* link = fillLst(sv,size);
    
    //Print the Linked List
    prntLst(link,10,size);
    
    destroy(link);

    return 0;
}

void destroy(Link *front){
    while(front!=NULL){
        Link *temp=front;
        front=front->next;
        delete temp;
    }
}

void prntLst(Link *next,int perLine,int n){
    int i=-1;
    for(int x=0;x < n;x++){
        if(i%perLine==(perLine-1))cout<<endl;
        cout<<next->data << " ";
        next=next->next;
        i++;
    }
}

Link *fillLst(SimpleVector<char> &sv,int n){
    //Initially create the front pointer/beginning pointer
    Link *front=new Link;
    front->data=sv[0];
    front->next=NULL;
    //If n>1 then fill with the data and links to the next
    Link *temp=front;
    for(int i=1;i<=n-1;i++){
        Link *nxtLink=new Link;
        nxtLink->data=sv[i];
        temp->next=nxtLink;
        temp=nxtLink;
    }
    temp->next=NULL;
    //Return the front of the list
    return front;
}

void prntVec(SimpleVector<char> &sv,int perLine,int size){
    cout<<endl;
    for(int i=0;i < size;i++){
        cout<<sv[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void fillVec(SimpleVector<char> &sv){
    for(int i=0;i<sv.size();i++){
        sv[i]=rand()%26+65;
    }
}

SimpleVector<char> pshFrnt(SimpleVector<char> &sv, int &size, char value) {
    if (sv.size() == size) { // Check if it has hit the limit
        int newSize = size * 2; // Double the size
        

        // Create a new vector with the doubled size
        SimpleVector<char> doubledVector(newSize);
        doubledVector[0]=value;

        // Initialize the new elements with the specified value
        for (int i = 1; i < newSize; ++i) {
            if (i-1 < size) {
                doubledVector[i] = sv[i-1];
                
            } else {
                doubledVector[i] = '\0';
            }
        }

        // Update the original vector size and data
        size++;
        
        return doubledVector;
    }
    else{
        SimpleVector<char> doubledVector(size+1);
        doubledVector[0]=value;
        for (int i = 1; i < size+1; ++i) {
            doubledVector[i] = sv[i-1];
        }
        size++;
        return doubledVector;
    }
    
}




SimpleVector<char> pshBack(SimpleVector<char> &sv, int &size, char value) {
    if (sv.size() == size) { // Check if it has hit the limit
        int newSize = size * 2; // Double the size

        // Create a new vector with the doubled size
        SimpleVector<char> doubledVector(newSize);

        // Copy the elements from the original vector to the new one
        for (int i = 0; i < size; ++i) {
            doubledVector[i] = sv[i];
        }

        // Add the new element at the back
        doubledVector[size] = value;

        // Fill the remaining elements with 'x'
        for (int i = size + 1; i < newSize; ++i) {
            doubledVector[i] = 'x';
        }
        // Update the original vector size
        size++;

        return doubledVector;
    } else {
        SimpleVector<char> doubledVector(size + 1);
        for (int i = 0; i < size; ++i) {
            doubledVector[i] = sv[i];
        }
        doubledVector[size] = value ;
        size++;
        return doubledVector;
    }
}

void popFrnt(SimpleVector<char> &sv, int &size) {
    if (size > 0) {
        // Shift all elements one position to the left
        for (int i = 1; i < size; ++i) {
            sv[i - 1] = sv[i];
        }

        // Decrease the size of the vector
        size--;
    }
}

void popBack(SimpleVector<char> &sv, int &size) {
    if (size > 0) {
        // Set the last element to '\0'
        sv[size - 1] = '\0';

        // Decrease the size of the vector
        size--;
    }
}