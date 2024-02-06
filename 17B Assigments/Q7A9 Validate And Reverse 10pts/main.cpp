/* 
 * File:   main.cpp
 * Author: YOUR NAME HERE
 * Created on DATE AND TIME HERE
 * Purpose:  Input something, output it reversed with some modifications
 * Note:Range should be 5 digits, 321 = 00321 reverse = 12300 before subtraction
 *      12300 - 999 = 11301 after subtraction
 *      12300 = 00321 = 321 after reversal and no subtraction
 */

//System Libraries Here
#include <iostream>//cin,cout,endl
#include <cstring> //strlen()
using namespace std;
//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
bool  inRange(const char [],unsigned short &);//Output true,unsigned or false
bool  reverse(unsigned short,signed short &);//Output true,short or false
short subtrct(signed short,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;     //More than enough
    char  digits[SIZE];    //Character digits or not
    unsigned short unShort;//Unsigned short
    short snShort;         //Signed short
    
    //Input or initialize values Here
    cout<<"Reverse a number and subtract if possible."<<endl;
    cout<<"Input a number in the range of an unsigned short"<<endl;
    cin>>digits;
    
    //Test if it is in the Range of an unsigned short
    if(!inRange(digits,unShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Reverse and see if it falls in the range of an signed short
    if(!reverse(unShort,snShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Now subtract if the result is not negative else don't subtract
    snShort=subtrct(snShort,999);
    
    //Output the result
    cout<<snShort<<endl;
    
    //Exit
    return 0;
}
bool inRange(const char digits[], unsigned short& un) {
    int i;
    // int size = sizeof(digits)/ sizeof(digits[0]);
    int size = strlen(digits);

    if (size > 5)
        return false;

    for (i = 0; i < size; i++) {
        if (!isdigit(digits[i]))
            return false;
    }

    int j = 0;
    int sum = 0;
    for (i = 0; i < size; i++) {
        sum = (digits[i] - '0') + (sum * 10);
    }

    if (sum > 0 && sum < 65535) {
        un = sum;
        return true;
    }
}
bool reverse(unsigned short unsign, signed short &sign){
    unsigned short reversedNumber = 0;
    int curpos = 10000 ;
    int remainder;
    while(unsign != 0)
    {
        remainder = unsign%10;
        reversedNumber += remainder * curpos;
        curpos /= 10; 
        unsign /= 10;
    }
        if (reversedNumber > 32767 ) 
        {
        return false;
        }
        else{
            sign = (signed short)reversedNumber;
                return true;
            }
        
    }
short subtrct(signed short sum, int num)
{
    short total = sum - num;
    if (total >= 0)
    {
        return total;
    }
    else
    {
        return sum;
    }


}