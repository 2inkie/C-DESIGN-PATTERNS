#include "Vanilla2.h"

VanillaOption::VanillaOption(const PayOff &_thePayOff, double _T) : T(_T) {
    thePayOffPtr = _thePayOff.clone();
}

double VanillaOption::getT() const { return T; }

double VanillaOption::OptionPayOff(double S) const {
    return (*thePayOffPtr)(S);
}

VanillaOption::VanillaOption(const VanillaOption &original) {
    T = original.T;
    thePayOffPtr = original.thePayOffPtr->clone();
}

VanillaOption &VanillaOption::operator=(const VanillaOption &original) {
    if (this != &original) {
        T = original.T;
        delete thePayOffPtr;
        thePayOffPtr = original.thePayOffPtr->clone();
    }

    return *this;
}

VanillaOption::~VanillaOption() { delete thePayOffPtr; }