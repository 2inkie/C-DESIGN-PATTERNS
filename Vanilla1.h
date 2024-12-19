#pragma once
#include "PayOff2.h"

class VanillaOption {
  public:
    VanillaOption(PayOff &_thePayOff, double _T);

    double GetExpiry() const;
    double OptPayOff(double S) const;

  private:
    double T;
    PayOff &thePayOff;
};