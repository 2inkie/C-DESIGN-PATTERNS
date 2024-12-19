#include "SimpleMC2.h"
#include <iostream>

using namespace std;

int main() {
    double T, K, S, vol, r;
    unsigned long tries;

    cin >> T >> K >> S >> vol >> r >> tries;

    PayOffCall callPayOff(K);
    PayOffPut putPayOff(K);

    double resultCall = SimpleMonteCarloPayOff(callPayOff, T, S, vol, r, tries);
    double resultPut = SimpleMonteCarloPayOff(putPayOff, T, S, vol, r, tries);

    cout << resultCall << "    " << resultPut;

    return 0;
}