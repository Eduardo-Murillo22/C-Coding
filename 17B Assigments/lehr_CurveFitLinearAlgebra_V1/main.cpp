/*Dr. Mark E. Lehr
  March 5th, 2020
  Purpose:  Curve fit of Data Structure empirical timing and/or
            operational analysis
	* He goes over this program during 9-18-23's Lecture.
 	
        ************************************************************
        *           YOU'RE ONLY CHANGING r.dat AND f.dat	
        ************************************************************ 
 
        * r.dat contains x data when the n^0, n^1, n^2 columns in the spreadsheet.
			
        * f.dat contains y` prime which is y+errors. 
	  Note when we get the data from our Fahr/Cels analysis we represented the errors, 
          so we are y prime. 
	 In farehnTemp spreadsheet we calculated y`prime with errors because it 
         represents us running the timing and operational analysis. Every computer is different, blah, blah.
			
	* c.dat prints 3 coefficients that we copy to the excel C0, C1, C2.
        * Use the coefficients to calculate the curve fit.			
*/
#include<iostream>
#include<iomanip>
using namespace std;

//User Libraries 
#include "mArray.h"

//Global Constants - Physics, Math, Conversions, Dimensions for
//function prototypes only!

//Function Prototypes

//Execution begins here
int main(){
    //Declare the Row and Empirical Data files
    char fn_r[]="r.dat";//r file name -> Set point X functional values
    mArray r(fn_r);     //Independent variable, form of the equation
    char fn_f[]="f.dat";//f file name -> Measured data Y
    mArray f(fn_f);     //Dependent variable, from empirical data run
    
    //Make the Sum of Squares Calculation c=(rt*r)^-1
    mArray rt(false,r); //Transpose of independent variable
    mArray c=mArray::invMat(rt*r)*rt*f;
    
    //Output the results
    char fn_c[]="c.dat";//c file name -> Functional Coefficients solutions
    c.mPrint(fn_c);     //Where curve fit coefficients are printed
    
    return 0;
}