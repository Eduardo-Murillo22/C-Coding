
#include <iostream>
#include <iomanip>  
using namespace std; 

struct p
{
    int p;
    int m;
    
};

int main(int argc, char** argv) {
    p p;
    p.m =10;
    p.p = 0;
           
    
    int num;
    cin >> num;
    
    if (num <= p.m && num >= p.p){
        cout << "WOrked";
    }
    else{
        cout << "no";
    }
      
}