#pragma once
#include "PayOff1.h"
#include "Random1.h"
#include <cmath>
#include <vector>

double SimpleMonteCarloPayOff(const PayOff &thePayOff, double T, double S0,
                              double vol, double r, unsigned long tries) {
    double rootVar = sqrt(vol * vol * T);
    double ito = -0.5 * rootVar;

    double movedS = S0 * exp(ito + r * T);
    double currentS;
    double currentSum = 0;
    double thisPayOff;

    vector<double> randNormNums = randNumGen(tries);

    for (unsigned long i = 0; i < tries; i++) {
        currentS = movedS * exp(rootVar * randNormNums[i]);
        thisPayOff = thePayOff(currentS);

        currentSum += thisPayOff;
    }

    double mean = currentSum / tries;
    mean *= exp(-r * T);

    return mean;
}