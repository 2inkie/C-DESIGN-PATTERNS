#include "SimpleMC.h"
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

vector<double> randNumGen(unsigned long tries) {
    vector<double> randNumVec(tries);

    random_device rd;
    mt19937 gen(rd());
    normal_distribution<> d(0, 1);

    for (unsigned long i = 0; i < tries; i++)
        randNumVec[i] = d(gen);

    return randNumVec;
}

double SimpleMonteCarloPayOff(const PayOff &thePayOff, double T, double S0,
                              double vol, double r, unsigned long tries) {
    double rootVar = sqrt(vol * vol * T);
    double ito = -0.5 * rootVar;

    double movedS = S0 * exp(ito + r * T);
    double currentS;
    double currentSum = 0;
    double thisPayOff;

    vector<double> randNormNums = randNumGen(tries);

    for (int i = 0; i < tries; i++) {
        currentS = movedS * exp(rootVar * randNormNums[i]);
        thisPayOff = thePayOff(currentS);

        currentSum += thisPayOff;
    }

    double mean = currentSum / tries;
    mean *= exp(-r * T);

    return mean;
}