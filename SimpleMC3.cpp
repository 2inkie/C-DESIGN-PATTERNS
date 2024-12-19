#include "SimpleMC3.h"
#include "Random1.h"
#include <cmath>

using namespace std;

double SimpleMonteCarlo3(const VanillaOption &theOption, double S, double vol,
                         double r, unsigned long tries) {
    double T = theOption.GetExpiry();

    double variance = vol * vol * T;
    double rootVar = sqrt(variance);
    double itoCor = -0.5 * variance;

    double movedS = S * exp(r * T + itoCor);
    double currS;
    double runningSum = 0;

    vector<double> a = randNumGen(tries);

    for (unsigned long i = 0; i < tries; i++) {
        currS = movedS * exp(rootVar * a[i]);
        double thisPayOff = theOption.OptPayOff(currS);

        runningSum += thisPayOff;
    }

    double mean = runningSum / tries;
    mean *= exp(-r * T);

    return mean;
}