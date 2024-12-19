#include "SimpleMC4.h"
#include "Random1.h"
#include <cmath>

using namespace std;

double SimpleMonteCarlo3(const VanillaOption &theOption, double S, double vol,
                         double r, unsigned long tries) {
    double T = theOption.getT();

    double var = vol * vol * T;
    double rootVar = sqrt(var);
    double Itos = -0.5 * var;

    double movedS = S * exp(r * T + Itos);
    double thisS;
    double runningSum = 0;

    vector<double> a = randNumGen(tries);

    for (unsigned long i = 0; i < tries; i++) {
        thisS = movedS * exp(rootVar * a[i]);
        double thisPayOff = theOption.OptionPayOff(thisS);
        runningSum += thisPayOff;
    }

    double mean = runningSum / tries;
    mean *= exp(-r * T);

    return mean;
}