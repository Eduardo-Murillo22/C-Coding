/* 
 * Author: Dr. Mark E. Lehr
 * Purpose:  Template aggregates
 */

//User Libraries
#include <iostream>
#include <iomanip>

#include"classTemplate.h"

using namespace std;


//Function Prototype
template<class T>
void prntRow(T *,int);
template<class T>
void prntTab(const Table<T> &);

//Execution Begins Here!
int main(int argc, char** argv) {
   //Initialize the random seed
   srand(static_cast<unsigned int>(time(0)));
   
   //Declare Variables
   int rows,cols;
   
   //Input the rows and the cols
   cout<<"Input the Rows and Columns for the Row and Table Arrays"<<endl;
   cin>>rows>>cols;
   
   //Test out the Row with integers and floats
   RowAray<int> a(rows);RowAray<float> b(cols);
   cout<<"Test the Integer Row with Rows"<<endl;
   prntRow(&a,rows);
   cout<<"Test the Float Row with Columns"<<endl;
   prntRow(&b,cols);
   
   //Test out the Table with a float
   Table<float> tab1(rows,cols);
   Table<float> tab2(tab1);
   Table<float> tab3=tab1+tab2;
   
   cout<<"Float Table 3 size is [row,col] = Table 1 + Table 2 ["
           <<rows<<","<<cols<<"]";
   cout<<endl<<"Table 1"<<endl;
   prntTab(tab1);
   cout<<"Table 2 copy of Table 1"<<endl;
   prntTab(tab2);
   cout<<"Table 3 addition of Table 1 and Table 2"<<endl;
   prntTab(tab3);
   
   //Exit Stage Right
   return 0;
}

template<class T>
void prntRow(T *a,int perLine){
    cout<<fixed<<setprecision(1)<<showpoint<<endl;
    for(int i=0;i<a->getSize();i++){
        cout<<a->getData(i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

template<class T>
void prntTab(const Table<T> &a){
    cout<<fixed<<setprecision(1)<<showpoint<<endl;
    for(int row=0;row<a.getSzRow();row++){
        for(int col=0;col<a.getSzCol();col++){
            cout<<setw(8)<<a.getData(row,col);
        }
        cout<<endl;
    }
    cout<<endl;
}