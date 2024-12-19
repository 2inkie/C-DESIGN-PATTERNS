#include "SimpleMC4.h"
#include "Vanilla2.h"
#include <iostream>

using namespace std;

int main() {
    double T, K, S, vol, r;
    unsigned long tries;

    cin >> T >> K >> S >> vol >> r >> tries;

    PayOffCall thePayOff(K);
    VanillaOption theOption(thePayOff, T);

    double result = SimpleMonteCarlo3(theOption, S, vol, r, tries);
    cout << result << endl;

    VanillaOption secondOption(theOption);

    result = SimpleMonteCarlo3(secondOption, S, vol, r, tries);

    cout << result << endl;

    PayOffPut otherPayOff(K);
    VanillaOption thirdOption(otherPayOff, T);
    theOption = thirdOption;

    result = SimpleMonteCarlo3(theOption, S, vol, r, tries);
    cout << result;

    return 0;
}