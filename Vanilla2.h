#pragma once

#include "PayOff3.h"

class VanillaOption {
  public:
    VanillaOption(const PayOff &_thePayOff, double _T);

    VanillaOption(const VanillaOption &original);
    VanillaOption &operator=(const VanillaOption &original);

    ~VanillaOption();

    double getT() const;
    double OptionPayOff(double S) const;

  private:
    double T;
    PayOff *thePayOffPtr;
};