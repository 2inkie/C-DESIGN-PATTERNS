#include <iostream>
#include "Random1.h"
#include <cmath>
#include <random>
#include <vector>

using namespace std;

double callOptMonteCarlo(double r, double K,
                         double S0, double vol,
                         double T, unsigned long tries)
{
    double leftProd = S0 * exp(r - 0.5 * vol * vol);
    double rightProd = exp(vol * sqrt(T));
    double ert = exp(-r * T);
    double sumToAverage = 0;
    double runningSum;

    vector<double> a = randNumGen(tries);

    for (unsigned long i = 0; i < tries; i++)
    {
        runningSum = leftProd * exp(vol * sqrt(T) * a[i]) - K;
        runningSum = runningSum > 0 ? runningSum : 0;
        sumToAverage += runningSum;
    }

    return (sumToAverage / tries) * ert;
}

int main()
{
    double r, K, S0, vol, T;
    unsigned long tries;

    double output;

    int a;

    cin >> r >> K >> S0 >> vol >> T >> tries;

    output = callOptMonteCarlo(r, K, S0, vol, T, tries);

    cout << output << endl;
}