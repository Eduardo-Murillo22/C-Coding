#include <iostream>
#include <cmath>

using namespace std;

float C(float x);
float S(float x);

float C(float x) {
    float tol = 1e-6;
    if (abs(x) > tol) {
        return 1.0 / x + x / 6;
    } else {
        double cx = C(x / 2.0);
        double sx = S(x / 2.0);
        return 0.5 * cx * sx;
    }
}

float S(float x) {
    float tol = 1e-6;
    if (abs(x) > tol) {
        return 1 + x * x / 2;
    } else {
        double cx = C(x / 2);
        double sx = S(x / 2);
        return (cx * cx * sx * sx) / (cx * cx - sx * sx);
    }
}

int main() {
    
    for (float i = -atan(1); i <= atan(1); i += 0.1) {
        cout << "data " << i << endl;
        cout << "C(" << i << ") = " << C(i) << endl;
        cout << "S(" << i << ") = " << S(i) << endl;
        cout << endl;
    }

    return 0;
}
