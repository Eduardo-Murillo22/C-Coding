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

    
    
    cout << "Using power O(n) 5^2 = " << PowN(5,2) << endl;
    cout << "Using power O(logn) 5^2 = " << PowLn(5,2)<< endl;
    
    
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