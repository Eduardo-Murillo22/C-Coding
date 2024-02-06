/*File:   MySTL.h
 * Author: Danielle*
 * Created on November 15, 2023, 7:32 PM
 */
#ifndef MYSTL_H
#define MYSTL_H
#include <bits/stdc++.h> 
#include "GHResults.h"
using namespace std;  //STD Name-space where Library is compiled
class MySTL {    
protected: 
    
    int cntCosG;    //g() counter
    int cntSinH; //h() counter    
    stack<float> radiansStck; // Radians [-1,1] incremented by 0.1    
    stack<float> hCount; 
    stack<float> gCount;
      
public:   
    
    MySTL();//Default Constructor
    virtual~MySTL(){cout<<"\nHit MySTL Destructor\n";}    
    
    // Setters
    float h(float); // sinh()
    float g(float); // cosh()
    void setStack(list<float>&);//(stack<string>&, list<string>&);
    void fillGuess(); //fill board with set<char> 
   
    // Getters
    void start();  
    void prntListFlt(list<float>&); // Scores
    void prntListStr(list<string>&); // first names    
    void prntStckFIFO();//stack<string>&);
    void prntStckRev();//stack<string>&);
    void prntGH(GHResults *ysin, std::stack<float>, string);
    void shuffleThis();//shuffles list fnames  
    void pause();
};
#endif /* MYSTL_H */

