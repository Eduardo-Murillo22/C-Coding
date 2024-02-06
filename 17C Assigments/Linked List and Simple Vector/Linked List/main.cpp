/*
    Author: Dr. Mark E. Lehr
    Date:   March 29th, 2021  1:12pm
    Purpose:Linked from first principles
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <cstdlib>     //NULL pointer
using namespace std;   //Library Name-space

//User Libraries
#include "Link.h"

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes


//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed

    //Declare variables
    LinkedList List;
    
    Link* lnk1 = List.fillLst(5);
    Link* newLink = List.create(10);
    List.prntLst(lnk1);//original list


    //add a element to the front
    List.pshFrnt(lnk1, newLink);
    List.prntLst(newLink);

//    //add element to the back
//    List.pshBack(lnk1, newLink);
//    List.prntLst(lnk1);
//
//    //delete element from the front
//    List.popFrnt(lnk1);
//    List.prntLst(lnk1);
//
//    //delete element from the back
//    List.popBack(lnk1);
//    List.prntLst(lnk1);

    //Delete all the allocated memory
    List.destroy(lnk1);

    //Exit stage right
    return 0;
}
