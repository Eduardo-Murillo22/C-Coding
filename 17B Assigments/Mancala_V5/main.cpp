//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries
#include<iomanip>
#include <cstring>
#include <fstream>



//Function Prototypes
#include"USER.h"




//Execution Begins Here
int main(int argc, char** argv) {
    
    User User;

    Player p1, p2;
    int board[SIZE];
    int pnum = 1;
    
    User.Start(p1,p2,pnum,board);
    
    
    return 0;
}