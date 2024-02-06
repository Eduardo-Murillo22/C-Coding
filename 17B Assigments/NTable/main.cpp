#include <iostream>
#include <cmath>

using namespace std;

double f(double x, double n) {
    return x * log(x) - n;
}

double f_prime(double x) {
    return 1 + log(x);
}

double inverse_n_log_n(double n) {
    // Initial guess for x, can be any reasonable value
    double x = 1.0;

    // Tolerance for convergence
    double tolerance = 1e-9;

    // Maximum number of iterations
    int max_iterations = 1000;

    // Iteratively apply Newton-Raphson method
    for (int i = 0; i < max_iterations; ++i) {
        double x_next = x - f(x, n) / f_prime(x);

        if (std::abs(x_next - x) < tolerance)
            return x_next;

        x = x_next;
    }

    std::cerr << "Newton-Raphson did not converge within the specified iterations." << std::endl;
    return std::nan(""); // Return NaN for failure
}

int main() {
    double n = 10.0;  // Replace this with the desired value of n
    cin  >> n;
    double x = inverse_n_log_n(n);

    if (!std::isnan(x))
        std::cout << "x = " << x << std::endl;
    else
        std::cout << "Failed to find the inverse." << std::endl;

    return 0;
}

