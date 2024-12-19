#include "Vanilla1.h"

VanillaOption::VanillaOption(PayOff &_thePayOff, double _T)
    : thePayOff(_thePayOff), T(_T) {}

double VanillaOption::GetExpiry() const { return T; }

double VanillaOption::OptPayOff(double S) const { return thePayOff(S); }