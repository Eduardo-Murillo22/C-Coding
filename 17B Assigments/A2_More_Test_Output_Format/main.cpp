/* 
 * File:main.cpp
 * Author:Eduardo Murillo
 * Date:2/22/2023
 * Purpose:Test Output Format
 * Version:v1
 */

//System Libraries - Post Here
#include <iostream>
using namespace std;

//User Libraries - Post Here
#include<iomanip>
//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here when needed

    //Declare variables or constants here
    //7 characters or less
    float num1, num2, num3,num4;

    //Initialize or input data here
    cin >> num1>> num2 >> num3 >> num4;

    //Display initial conditions, headings here

    //Process inputs  - map to outputs here

    //Format and display outputs here
    cout<<fixed<<setprecision(0);

    cout << setw(9) << num1;
    cout << setw(10) <<setprecision(1)<< num1;
    cout << setw(10) << setprecision(2)<< num1 << endl;
    cout << setprecision(0);
    cout << setw(9) << num2;
    cout << setw(10) <<setprecision(1)<< num2;
    cout << setw(10) << setprecision(2)<< num2 << endl;
    cout << setprecision(0);
    cout << setw(9) << num3;
    cout << setw(10) <<setprecision(1)<< num3;
    cout << setw(10) << setprecision(2)<< num3 << endl;
    cout << setprecision(0);
    cout << setw(9) << num4;
    cout << setw(10) <<setprecision(1)<< num4;
    cout << setw(10) << setprecision(2)<< num4;
    //Clean up allocated memory here

    //Exit stage left
    return 0;
}