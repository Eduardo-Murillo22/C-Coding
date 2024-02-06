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

    Object b(20);
    SimpleVector<Object> svp;
    int beg,end;

    // Measure the time for pushing an object
    beg = time(0);
    for(int i=0;i < 1000;i++){
        svp.push(b); 
    }
    end = time(0);
    cout << "For N=" << svp.size() << " Select Sort Takes "
            << end - beg << " Seconds" << endl;
    cout << endl << endl;
    
    
//    cout<<"Simple Vector Push next object"<<svp[svp.size()-1];
    //Exit
    return 0;
}