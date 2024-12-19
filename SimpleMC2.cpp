#include "PayOff1.h"
#include "Random1.h"
#include "SimpleMC.h"
#include <iostream>

using namespace std;

int main() {
    double T, K, S, vol, r;
    unsigned long tries;

    cin >> T >> K >> S >> vol >> r >> tries;

    PayOff callPayOff(K, PayOff::call);
    PayOff putPayOff(K, PayOff::put);

    double resultCall = SimpleMonteCarloPayOff(callPayOff, T, S, vol, r, tries);
    double resultPut = SimpleMonteCarloPayOff(putPayOff, T, S, vol, r, tries);

    cout << resultCall << "    " << resultPut;

    double abc;

    cin >> abc;

    return 0;
}