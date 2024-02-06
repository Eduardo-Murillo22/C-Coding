/* 
 * File:   main.cpp
 * Author: Eduardo Murillo
 * 
 * Created on October 31, 2023, 12:57 PM
 */

#include <iostream>
#include <cmath>

using namespace std;

float g(float,float);

/*
 * 
 */
int main(int argc, char** argv) {
    float tol = 1e-6;
    
    for(float x = -1.0;x <= 1.0+tol;x += 0.1){
        cout << "g(" << x << ") = " << g(x,tol) << endl;
    }
    
    return 0;
}

float g(float x,float tol){
    
    
    if(abs(x) < tol){
        
        return (x - pow(x, 3))/6;
        
    }
    else{

        double g_x = g(x / 2.0, tol);
        return 2 * g_x / (1 + g_x * g_x);
        
    }
    
}