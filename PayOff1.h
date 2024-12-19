#pragma once
#include <algorithm>

using namespace std;

class PayOff {
  public:
    enum OptType { call, put };
    PayOff(double _K, OptType _TOptType);

    double operator()(double S0) const {
        switch (TOptType) {
        case call:
            return max(S0 - K, 0.0);

        case put:
            return max(K - S0, 0.0);

        default:
            throw("Djaskay se!");
        }
    }

  private:
    double K;
    OptType TOptType;
};