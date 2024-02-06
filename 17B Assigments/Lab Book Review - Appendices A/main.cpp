/* 
 * File:   main.cpp
 * Author: Eduardo Murillo
 *
 * Created on August 31, 2023, 2:55 PM
 */

#include <iostream>

using namespace std;


int main(int argc, char** argv) {
    
    int C=0,n=0,m=0;
    int sum =0, sum2 = 0;
    
    cout << "n\n∑ C=f(C,n,m)\ni = m"  << endl;
    
    cout << "Enter your variable m (Starting index)" << endl;
    cin >> m;
    cout << "Enter the n (Ending index)"<< endl;
    cin >> n;
    cout << "Enter the C (index summation)" << endl;
    cin >> C;
    
    cout << "Sum the series using a for-loop : ";
    
    for(int o=m; o <= n; o++){
        sum += C;
    }
    cout << sum << endl;
    cout << "for(int o=m; o <= n; o++){\nsum += C;\n}" << endl;
    
    
    
    cout << "Using the formula derived from above: ";
    
    // n
    // ∑ C = C.(n-m+1)
    //i=m
    
    
    sum2 = C*(n-m+1);
    cout << sum2 << endl;
    cout << "sum2 = C*(n-m+1);" << endl;
    
    
    
    return 0;
}

