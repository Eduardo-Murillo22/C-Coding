#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct data{
    float F;
    float C;
    float error;
};
struct SUM {

    float X = 0;
    float XX = 0;
    float YP = 0; 
    float XY = 0;
};

void Print(SUM &);
void CalSum(SUM &, data *,int);

int main() {
    ifstream inputFileC("Data.txt");
    SUM sum;
    int size;
    
    inputFileC >> size;//Y
    data* Data = new data[size+1];
    
    for (int i = 1; i < size+1; i++) {
        inputFileC >> Data[i].F >> Data[i].C >> Data[i].error;
    }
    
    // solve for sumX
    CalSum(sum,Data,size);

    Print(sum);

    delete[] Data;
    
    return 0;
}

void CalSum(SUM &sum,data *Data, int size){

    float M = 0.5556;
    float B = -17.7778;
    for (int i = 1; i < size + 1; i++) {
        sum.X += Data[i].F;
        sum.XX += Data[i].F * Data[i].F;
        sum.YP += M * Data[i].F + B + Data[i].error;
        sum.XY += Data[i].F * (M * Data[i].F + B + Data[i].error);
    }
    
}

void Print(SUM &sum){

    cout << fixed << setprecision(2);
    cout << "sumX = " << sum.X << endl;
    cout << "sumY' = " << sum.YP << endl;
    cout << "sumX*X = " << sum.XX << endl;
    cout << "sumX*Y = " << sum.XY << endl;
    float DM = ((sum.X * sum.YP) - (37 * sum.XY)) / ((sum.X * sum.X) - (37 * sum.XX));
    float DB = (sum.YP -DM * sum.X) / 37;
    cout << "Derived M = " << DM << endl;
    cout << "Derived B = " << DB << endl;
    
}