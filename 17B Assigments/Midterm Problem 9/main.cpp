/* 
 * File:   main.cpp
 * Author: HP Omen
 *
 * Created on October 28, 2023, 10:30 PM
 */

#include <iostream>

int PowLn(int , unsigned int );
int PowN(int x, int n);

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    
    for(int i=1;i < 11;i++){
        for(int x=1;x < 6;x++){
            cout << "Using power O(n) "<<i<<"^"<<x<<" = " << PowN(i,x) << endl;
            cout << "Using power O(logn) " << i << "^" << x <<" = " << PowLn(i,x)<< endl;
        }
        cout << endl << endl;;
    }
    
    
    return 0;
}


// O(logn)
int PowLn(int x, unsigned int y) {
    int temp;
    if (y == 0)
        return 1;
    temp = PowLn(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}

// O(n)
int PowN(int x, int n)
{
	// If x^0 return 1
	if (n == 0)
		return 1;
	// If we need to find of 0^y
	if (x == 0)
		return 0;
	// For all other cases
	return x * PowN(x, n - 1);
}