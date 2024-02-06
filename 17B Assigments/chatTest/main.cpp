#include <iostream>
#include <iomanip>
#include <stack>
#include <list>

using namespace std;

float h(float);
float g(float);

int CCall = 1, SCall = 1;

list<float> andRad = {-1, -0.9, -0.8, -0.7, -0.6, -0.5, -0.4, -0.3, -0.2, -0.1, 0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1};

stack<int> SinCallsSIN;
stack<int> CosCallsSIN;

stack<int> SinCallsCOS;
stack<int> CosCallsCOS;

int main(int argc, char** argv) {
    // Testing out recursive trig functions
    int numloop = 0;

    list<float> RSin;
    list<float> RCos;
    //this is to count the calls when you calculate the COSH

    for (float value : andRad) {
        SCall = 1;
        CCall = 1;
        if (numloop == 9) {
            RSin.push_front(h(-0.1));
        } else if (numloop == 10) {
            RSin.push_front(h(0));
        } else {
            RSin.push_front(h(value));
        }

        // Store the number of calls to h in the SinCalls stack
        SinCallsSIN.push(SCall);
        CosCallsSIN.push(CCall);
        numloop++;
    }
    //this is to count the calls when you calculate the COSH
    numloop = 0;
    for (float value : andRad) {
        SCall = 1;
        CCall = 1;
        if (numloop == 9) {
            RCos.push_front(g(-0.1));
        } else if (numloop == 10) {
            RCos.push_front(g(0));
        } else {
            RCos.push_front(g(value));
        }

        // Store the number of calls to h in the SinCalls stack
        SinCallsCOS.push(SCall);
        CosCallsCOS.push(CCall);
        numloop++;
    }

    numloop = 0;
    cout << "RAD" << setw(20) << "Results SinH" << setw(20) << "Cos calls" << setw(20) << "Sin calls" << endl;
    for (float value : andRad) {
        if (numloop == 9) {
            cout << "-0.1" << setw(20) << RSin.front() << setw(20) << CosCallsSIN.top() << setw(20) << SinCallsSIN.top() << endl;
        } else if (numloop == 10) {
            cout << "0" << setw(20) << RSin.front() << setw(20) << CosCallsSIN.top() << setw(20) << SinCallsSIN.top() << endl;
        } else {
            cout << value << setw(20) << RSin.front() << setw(20) << CosCallsSIN.top() << setw(20) << SinCallsSIN.top() << endl;
        }
        CosCallsSIN.pop();
        SinCallsSIN.pop();
        RSin.pop_front();
        numloop++;
    }

    cout << endl << endl;
    numloop = 0;
    cout << "RAD" << setw(20) << "Results CosH" << setw(20) << "Cos calls" << setw(20) << "Sin calls" << endl;
    for (float value : andRad) {
        if (numloop == 9) {
            cout << "-0.1" << setw(20) << RCos.front() << setw(20) << CosCallsCOS.top() << setw(20) << SinCallsCOS.top() << endl;
        } else if (numloop == 10) {
            cout << "0" << setw(20) << RCos.front() << setw(20) << CosCallsCOS.top() << setw(20) << SinCallsCOS.top() << endl;
        } else {
            cout << value << setw(20) << RCos.front() << setw(20) << CosCallsCOS.top() << setw(20) << SinCallsCOS.top() << endl;
        }
        CosCallsCOS.pop();
        SinCallsCOS.pop();
        RCos.pop_front();
        numloop++;
    }

    // Exit stage right
    return 0;
}

float h(float angR) { // Sin
    float tol = 1e-6;
    if (angR > -tol && angR < tol)
        return angR + angR * angR * angR / 6;
    SCall++;
    return 2 * h(angR / 2) * g(angR / 2);
}

float g(float angR) { // Cos
    float tol = 1e-6;
    if (angR > -tol && angR < tol)
        return 1 + angR * angR / 2;
    float b = h(angR / 2);
    CCall++;
    return 1 + 2 * b * b;
}
