#include <iostream>
#include <iomanip>
#include <stack>
#include <list>

using namespace std;

float h(float);
float g(float);

stack<int> SinCallsSIN;
stack<int> CosCallsCOS;

int main(int argc, char** argv) {
    // Testing out recursive trig functions
    int numloop = 0;
    
    numloop = 0;
    cout << "RAD" << setw(20) << "Results SinH" << setw(20) << "Cos calls" << setw(20) << "Sin calls" << endl;
    for (float andRad = -1; andRad <= 1; andRad += 0.1) {
        if (numloop == 9) {
            cout << "-0.1" << setw(20) << h(-0.1) << setw(20);
            cout << CosCallsCOS.size() << setw(20) << SinCallsSIN.size() << endl;
        } else if (numloop == 10) {
            cout << "0" << setw(20) << h(0) << setw(20);
            cout << CosCallsCOS.size() << setw(20) << SinCallsSIN.size() << endl;
        } else {
            cout << andRad << setw(20) << h(andRad) << setw(20);
            cout << CosCallsCOS.size() << setw(20) << SinCallsSIN.size() << endl;
        }
        // Clear the stacks
        while (!CosCallsCOS.empty()) {
            CosCallsCOS.pop();
        }
        while (!SinCallsSIN.empty()) {
            SinCallsSIN.pop();
        }

        numloop++;
    }
    
    cout << endl << endl;
    numloop = 0;
    cout << "RAD" << setw(20) << "Results CosH" << setw(20) << "Cos calls" << setw(20) << "Sin calls" << endl;
    for (float andRad = -1; andRad <= 1; andRad += 0.1) {
        if (numloop == 9) {
            cout << "-0.1" << setw(20) << g(-0.1) << setw(20);
            cout << CosCallsCOS.size() << setw(20) << SinCallsSIN.size() << endl;
        } else if (numloop == 10) {
            cout << "0" << setw(20) << g(0) << setw(20);
            cout << CosCallsCOS.size() << setw(20) << SinCallsSIN.size() << endl;
        } else {
            cout << andRad << setw(20) << g(andRad) << setw(20);
            cout << CosCallsCOS.size() << setw(20) << SinCallsSIN.size() << endl;
        }
        // Clear the stacks
        while (!CosCallsCOS.empty()) {
            CosCallsCOS.pop();
        }
        while (!SinCallsSIN.empty()) {
            SinCallsSIN.pop();
        }

        numloop++;
    }

    // Exit stage right
    return 0;
}

float h(float angR) { // Sin
    SinCallsSIN.push(1);
    float tol = 1e-6;
    if (angR > -tol && angR < tol)
        return angR + angR * angR * angR / 6;

    return 2 * h(angR / 2) * g(angR / 2);
}

float g(float angR) { // Cos
    CosCallsCOS.push(1);
    float tol = 1e-6;
    if (angR > -tol && angR < tol)
        return 1 + angR * angR / 2;
    float b = h(angR / 2);

    return 1 + 2 * b * b;
}
