/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Purpose:  Test out push values onto simple vector
 *           with a very complex object
 *           Note:  This simple vector only works with objects
 *           Also overloading the == operator in this version of Object
 *           Simple Vector using Linked List
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
using namespace std;

//User Libraries
#include "Object.h"       //2D Object
#include "SimpleVector.h" //Simple Vector only works with Classes

//Global Constants

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int> (time(0)));

    Object a(1), b(1);

    SimpleVector<Object> svp(a);

    for (int i = 0; i < 80; i++) {
        svp.push(b);
    }
    
    cout << "Operational analysis for N = " << svp.size()-1 << " Before  the function =" << Op << endl;
    cout << "Operational analysis for N = " << svp.size()-1 << " Before do   the loop =" << Ob << endl;
    cout << "Operational analysis for N = " << svp.size()-1 << " in the do       loop =" << Odo << endl;
    cout << "Operational analysis for N = " << svp.size()-1 << " after       the loop =" << Oa << endl;
    cout << "Total Number of operations = " << Op+Ob+Odo+Oa << endl;
    
    return 0;
    
}