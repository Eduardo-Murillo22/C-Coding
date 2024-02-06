/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Purpose:  To Test and Modify the Simple Vector
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
using namespace std;

template <class T>
class SimpleVector
{
private:
   T *aptr;          // To point to the allocated array
   int arraySize;    // Number of elements in the array
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range

public:
   // Default constructor
   SimpleVector()
      { aptr = 0; arraySize = 0;}
      
   // Constructor declaration
   SimpleVector(int);
   
   // Copy constructor declaration
   SimpleVector(const SimpleVector &);
   
   // Destructor declaration
   ~SimpleVector();
   
   // Accessor to return the array size
   int size() const
      { return arraySize; }

   // Accessor to return a specific element
   T getElementAt(int position);

   // Overloaded [] operator declaration
   T &operator[](const int &);
   
   //Adding 4 functions Push front/back, Pop front/back
   void pshFrnt(T);
   void pshBack(T);
   T popFrnt();
   T popBack();
};

//*******************************************
//Student to code these functions
//*******************************************

template <class T>
void SimpleVector<T>::pshFrnt(T val)
{
    // Allocate memory for the new array.
    T *newArr = new T[arraySize + 1];

    // Move the elements of the old array one index forward.
    for(int i = 0; i < arraySize; i++)
        newArr[i + 1] = aptr[i];

    // Add the new element at the front of the array.
    newArr[0] = val;

    // Delete the old array.
    delete [] aptr;

    // Point to the new array.
    aptr = newArr;

    // Increment the array size.
    arraySize++;
}

template <class T>
void SimpleVector<T>::pshBack(T val)
{
    // Allocate memory for the new array.
    T *newArr = new T[arraySize + 1];

    // Copy the elements of the old array.
    for(int i = 0; i < arraySize; i++)
        newArr[i] = aptr[i];

    // Add the new element at the back of the array.
    newArr[arraySize] = val;

    // Delete the old array.
    delete [] aptr;

    // Point to the new array.
    aptr = newArr;

    // Increment the array size.
    arraySize++;
}

template <class T>
T SimpleVector<T>::popFrnt()
{
    if (arraySize == 0)
        throw "ERROR: Cannot remove an element from an empty array.\n";
    
    // Get the value of the front element.
    T val = aptr[0];

    // Allocate memory for the new array.
    T *newArr = new T[arraySize - 1];

    // Copy the elements of the old array starting from index 1.
    for(int i = 1; i < arraySize; i++)
        newArr[i - 1] = aptr[i];

    // Delete the old array.
    delete [] aptr;

    // Point to the new array.
    aptr = newArr;

    // Decrement the array size.
    arraySize--;

    // Return the value of the front element.
    return val;
}

template <class T>
T SimpleVector<T>::popBack()
{
    if (arraySize == 0)
        throw "ERROR: Cannot remove an element from an empty array.\n";
    
    // Get the value of the back element.
    T val = aptr[arraySize - 1];

    // Allocate memory for the new array.
    T *newArr = new T[arraySize - 1];

    // Copy the elements of the old array up to the second last element.
    for(int i = 0; i < arraySize - 1; i++)
        newArr[i] = aptr[i];

    // Delete the old array.
    delete [] aptr;

    // Point to the new array.
    aptr = newArr;

    // Decrement the array size.
    arraySize--;

    // Return the value of the back element.
    return val;
}

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
   arraySize = s;
   // Allocate memory for the array.
   try
   {
      aptr = new T [s];
   }
   catch (bad_alloc)
   {
      memError();
   }

   // Initialize the array.
   for (int count = 0; count < arraySize; count++)
      *(aptr + count) = 0;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
   // Copy the array size.
   arraySize = obj.arraySize;
   
   // Allocate memory for the array.
   aptr = new T [arraySize];
   if (aptr == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int count = 0; count < arraySize; count++)
      *(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
   if (arraySize > 0)
      delete [] aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}
#endif

//Global Constants

//Function prototypes
int mrkRand(int seed=0);
void fillVec(SimpleVector<char> &);
void prntVec(SimpleVector<char> &,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int size;
    cout<<"Input the Size of the Array 10-100"<<endl;
    cin>>size;
    cout<<"The array Size = "<<size<<endl;
    SimpleVector<char> sv(size);
    
    //Fill the Vector
    fillVec(sv);
    
    //Print the Vector
    prntVec(sv,10);
    
    //Add a value to the array
    char vlFrnt=mrkRand()%26+65;
    char vlBack=mrkRand()%26+65;
    cout<<"The value added to the front is = "<<vlFrnt<<endl;
    cout<<"The value added to the back  is = "<<vlBack<<endl;
    sv.pshFrnt(vlFrnt);
    sv.pshBack(vlBack);
    
    //Print the Vector
    prntVec(sv,10);
    
    //Remove 2 from the Front and 2 from the back
    cout<<endl;
    cout<<"Remove 2 from the front and back"<<endl;
    cout<<"Front Removed = "<<sv.popFrnt()<<endl;
    cout<<"Front Removed = "<<sv.popFrnt()<<endl;
    cout<<"Back  Removed = "<<sv.popBack()<<endl;
    cout<<"Back  Removed = "<<sv.popBack()<<endl;
    
    //Print the Vector
    prntVec(sv,10);

    return 0;
}

void prntVec(SimpleVector<char> &sv,int perLine){
    cout<<endl;
    for(int i=0;i<sv.size();i++){
        cout<<sv[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void fillVec(SimpleVector<char> &sv){
    for(int i=0;i<sv.size();i++){
        sv[i]=mrkRand(sv.size())%26+65;
    }
}

int mrkRand(int seed){
    //Xn+1 = (aXn + c) mod m
    //where X is the sequence of pseudo-random values
    //m, 0 < m  - modulus 
    //a, 0 < a < m  - multiplier
    //c, 0 ≤ c < m  - increment
    //x0, 0 ≤ x0 < m  - the seed or start value
    unsigned int a=31051;      //Short Prime
    unsigned int c=997;        //Another Prime
    unsigned int shrt=1<<15-1; //Range of positive signed short
    unsigned int m=1<<31-1;    //Range of positive signed int
    static int Xn=30937;       //Short Prime
    static int cnt=0;          //Initialize the seed
    if(cnt==0&&seed<=shrt)Xn=seed;
    cnt++;
    Xn=(a*Xn+c)%m;
    return Xn;
}