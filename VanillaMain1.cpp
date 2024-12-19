#include "DoubleDigital.h"
#include "SimpleMC3.h"
#include "Vanilla1.h"
#include <iostream>

using namespace std;

int main() {
    double T, LB, UB, S, vol, r;
    unsigned long tries;

    cin >> T >> LB >> UB >> S >> vol >> r >> tries;

    PayOffDoubleDigital PDD(LB, UB);
    VanillaOption Opt(PDD, T);

    double ans = SimpleMonteCarlo3(Opt, S, vol, r, tries);

    cout << ans;

    bool a;
    cin >> a;
}