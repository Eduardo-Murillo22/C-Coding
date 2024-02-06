/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Purpose:  Test out push values onto simple vector
 *           with a very complex object
 *           Note:  This simple vector only works with objects
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
using namespace std;

//User Libraries
#include "Object.h"       //2D Objects
#include "SimpleVector.h" //Simple Vector only works with Classes

//Global Constants

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    Object b(1);
    SimpleVector<Object> svp;
    int beg,end;


    for(int i = 0;i < 100;i++){
        svp.push(b); 
    }
    
    cout << "Operational analysis for N = " << svp.size() << " before the loop =" << Ob << endl;
    cout << "Operational analysis for N = " << svp.size() << " in count loop   =" << Oc << endl;
    cout << "Operational analysis for N = " << svp.size() << " after  the loop =" << Oa << endl;
    cout << "Total number of operations = " << Ob+Oc+Oa << endl;

    
    

    return 0;
}