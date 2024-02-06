/* 
 * File:   main.cpp
 * Author: YOUR NAME HERE
 * Created on DATE AND TIME HERE
 * Purpose:  Sorting a 2-D array of characters if row and columns match
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int);//Sort by row
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    
    //Input the size of the array you are sorting
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    }else{
        if(rowDet!=rowIn)
        cout<<(rowDet<rowIn?"Row Input size less than specified.":
            "Row Input size greater than specified.")<<endl;
        if(colDet!=colIn)
        cout<<(colDet<colIn?"Column Input size less than specified.":
            "Column Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}

int read(char arr[][COLMAX], int& rows)
{
    int numRow=0,colsize=0;
    while(cin >> arr[numRow])
    {
        colsize = strlen(arr[numRow]) > colsize ? strlen(arr[numRow]) : colsize;
        numRow++;
    }
    rows = numRow != rows ? numRow : rows;
    return colsize;

}

void sort(char a[][COLMAX], int rows, int cols)
{
    char temp;
    int c = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < (rows -1 ); j++) {

            if (strcmp(a[i], a[j]) < 0)
            {
                c++;
                    for (int k = 0; k < cols; k++) {
                        swap(a[i][k], a[j][k]);
                }
            }
            if (a[i][0] < a[j][0]) {
                for (int k = 0; k < cols; k++) {
                    swap(a[i][k], a[j][k]);
                }
            }

        }

    }
}

void print(const char arr[][COLMAX], int R, int C)
{
 for(int i =0 ;i < R;i++)
 {
         cout << arr[i];
    cout << endl; 
 }
}