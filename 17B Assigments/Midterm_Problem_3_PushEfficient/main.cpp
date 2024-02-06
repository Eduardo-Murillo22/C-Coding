/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Purpose:  Test out push values onto simple vector
 *           with a very complex object
 *           Note:  This simple vector only works with objects
 *           Also overloading the == operator in this version of Object
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

    srand(static_cast<unsigned int> (time(0)));

    Object a(1), b(90);

    SimpleVector<Object> svp(a);
    int beg, end;

    // Measure the time for pushing an object
    beg = time(0);
    for (int i = 0; i < 60000; i++) {
        svp.push(b);
    }
    end = time(0);
    cout << "For N=" << svp.size() << " Select Sort Takes "
            << end - beg << " Seconds" << endl;
    cout << endl << endl;
    
    //Exit
    return 0;
}