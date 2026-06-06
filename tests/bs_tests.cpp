#include <gtest/gtest.h>
#include <cmath>

double N(double x) { return 0.5 * std::erfc(-x / std::sqrt(2.0)); }
double bs_call(double S, double K, double r, double sigma, double T) {
    double d1 = (std::log(S/K) + (r+0.5*sigma*sigma)*T)/(sigma*std::sqrt(T));
    double d2 = d1 - sigma*std::sqrt(T);
    return S*N(d1) - K*std::exp(-r*T)*N(d2);
}

TEST(BlackScholes, ATMCall) { EXPECT_NEAR(bs_call(100,100,0.05,0.2,1.0), 10.4506, 1e-3); }
TEST(BlackScholes, ITMCall) { EXPECT_NEAR(bs_call(110,100,0.05,0.2,1.0), 17.0000, 1.0); }
TEST(BlackScholes, OTMCall) { EXPECT_NEAR(bs_call(90,100,0.05,0.2,1.0),  5.5000,  1.0); }
