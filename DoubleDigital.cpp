#include "DoubleDigital.h"

PayOffDoubleDigital::PayOffDoubleDigital(double _LB, double _UB)
    : LB(_LB), UB(_UB) {}
double PayOffDoubleDigital::operator()(double S) const {
    if (S <= LB) {
        return 0;
    }

    if (S >= UB) {
        return 0;
    }

    return 1;
}