#include <iostream>
#include <cmath>

double N(double x) { return 0.5 * std::erfc(-x / std::sqrt(2.0)); }

double bs_call(double S, double K, double r, double sigma, double T) {
    double d1 = (std::log(S/K) + (r + 0.5*sigma*sigma)*T) / (sigma*std::sqrt(T));
    double d2 = d1 - sigma*std::sqrt(T);
    return S*N(d1) - K*std::exp(-r*T)*N(d2);
}

int main() {
    std::cout << "BS call: " << bs_call(100,100,0.05,0.2,1.0) << std::endl;
    return 0;
}
