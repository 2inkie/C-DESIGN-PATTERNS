#include "DoubleDigital.h"
#include "SimpleMC2.h"
#include <iostream>

using namespace std;

int main() {
    double T, LB, UB, S, vol, r, a;
    unsigned long tries;

    cin >> T >> LB >> UB >> S >> vol >> r >> tries;

    PayOffDoubleDigital thePayOff(LB, UB);

    double result = SimpleMonteCarloPayOff(thePayOff, T, S, vol, r, tries);

    cout << result;

    cin >> a;
}