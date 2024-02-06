/* 
 * Author: Dr. Mark E. Lehr
 * Purpose:  Template aggregates
 */

//User Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
template<class T>
class RowAray{
    protected:
        int size;
        T *rowData;
    public:
        RowAray(int);
        virtual ~RowAray();
        int mrkRand(int);
        int getSize()const{return size;}
        T getData(int i)const{
            if(i>=0&&i<size)return rowData[i];
            else return 0;}
        void setData(int,T);
};

template<class T>
int RowAray<T>::mrkRand(int seed){
    //Xn+1 = (aXn + c) mod m
    //where X is the sequence of pseudo-random values
    //m, 0 < m  - modulus 
    //a, 0 < a < m  - multiplier
    //c, 0 ≤ c < m  - increment
    //x0, 0 ≤ x0 < m  - the seed or start value
    unsigned int a=31051;      //Short Prime
    unsigned int c=997;        //Another Prime
    unsigned int shrt=1<<15-1; //Range of positive signed short
    unsigned int m=1<<31-1;    //Range of positive signed int
    static int Xn=30937;       //Short Prime
    static int cnt=0;          //Initialize the seed
    if(cnt==0&&seed<=shrt)Xn=seed;
    cnt++;
    Xn=(a*Xn+c)%m;
    return Xn;
}

template<class T>
RowAray<T>::RowAray(int n){
    size=n;
    rowData=new T[size];
    for(int i=0;i<size;i++){
        rowData[i]=mrkRand(size)%90+10;
    }
}

template<class T>
RowAray<T>::~RowAray(){
    delete []rowData;
}

template<class T>
void RowAray<T>::setData(int row,T val){
    if(row>=0&&row<size)rowData[row]=val;
    else rowData[row]=0;
}

template<class T>
class Table{
    protected:
        int szRow;
        int szCol;
        RowAray<T> **columns;
    public:
        Table(unsigned int,unsigned int);
        Table(const Table<T> &);
        virtual ~Table();
        int getSzRow()const {return szRow;}
        int getSzCol()const {return szCol;}
        T getData(int,int)const;
        void setData(int,int,T);
        Table<T> operator+(const Table<T> &);
};

template<class T>
Table<T>::Table(unsigned int rows, unsigned int cols){
    szRow=rows;
    szCol=cols;
    columns=new RowAray<T>*[cols];
    for(int i = 0 ; i < cols ; i++){
            columns[i]=new RowAray<T>(rows);
    }
}

template<class T>
Table<T>::Table(const Table &a) {
    //Student to correct/complete
    szRow = a.szRow;
    szCol = a.szCol;
    columns = new RowAray<T>*[szCol];
    for (int i = 0; i < szCol; i++) {
        columns[i] = new RowAray<T>(szRow);
        for (int j = 0; j < szRow; j++) {
            T val = a.getData(j, i);
            columns[i]->setData(j, val);
        }
    }
}

template<class T>
Table<T>::~Table(){
for (int i = 0; i < szCol; i++) {
    delete columns[i];
}
    delete []columns;
}

template<class T>
T Table<T>::getData(int row,int col)const{\
    
    return columns[col]->getData(row);
}


template<class T>
void Table<T>::setData(int row,int col,T val){
    columns[col]->setData(row, val);
}

template<class T>
Table<T> Table<T>::operator+(const Table<T> &a) {
    Table<T> result(szRow, szCol); // Create a new table for the result

    for (int i = 0; i < szRow; i++) {
        for (int j = 0; j < szCol; j++) {
            result.setData(i, j, this->getData(i, j) + a.getData(i, j)); // Add corresponding elements
        }
    }

    return result;
}



