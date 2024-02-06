//Assignment Permutation and Combination Comparison
//Author: Eduardo Murillo
// Date: 10/25/23


#include<iostream> 
#include <iomanip>

using namespace std;

double nPmR(int,int);
double nPm(int,int);
double nCmR(int,int);
double nCm(int,int);

int pow(int x,int y){
    if(y <= 0)return 1;
    
    return pow(x,y-1)*x;
}

int main(){
    int m, n;
    //Formate display
    cout << left << setw(5) << "n" << left << setw(5) << "m" << left << setw(15) << "Permutation" << left 
            << setw(30) << "Permutation Replacement"
            << left << setw(15) << "Combination" << left << setw(30) << "Combination Replacement" << endl;

    
    for (n = 2; n <= 26; n++) {
        for (m = 0; m <= n; m++) {
            
            cout << left << setw(5) << n << left 
                    << setw(5) << m << left << setw(15) 
                    << nPm(n, m) << left << setw(30) << nPmR(n, m) 
                    << left << setw(15) << nCm(n, m) << left << setw(30) 
                    << nCmR(n, m) << endl;

        }

    }

}

double nPmR(int n ,int m){
    
    return pow(n,m);
    
}

double nPm(int n,int m){
    double sumN = 1 ,sumNM = 1;
    
    for(int i=1;i <= n;i++)
        sumN *= i;

    for (int i = 1; i <= (n-m); i++)
        sumNM *= i;
    
    return (sumN/sumNM);
    
}

double nCmR(int n,int m){
    
    double nm2 = 1, n2 = 1, m2 = 1;

    for (int i = 1; i <= (n+m-1); i++)
        nm2 *= i;

    for (int i = 1; i <= (n-1); i++)
        n2 *= i;

    for (int i = 1; i <= m; i++)
        m2 *= i;
    
    
    return  (nm2/(m2*n2));
    
}

double nCm(int n,int m){

    double nmF = 1, nF = 1, mF = 1;

    for (int i = 1; i <= n; i++)
        nF *= i;

    for (int i = 1; i <= (n - m); i++)
        nmF *= i;

    for (int i = 1; i <= m; i++)
        mF *= i;

    
    return (nF / (nmF * mF));
    
}