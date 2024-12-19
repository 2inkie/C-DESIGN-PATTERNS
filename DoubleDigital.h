#pragma once
#include "PayOff2.h"

class PayOffDoubleDigital : public PayOff {
  public:
    PayOffDoubleDigital(double _LB, double _UB);
    virtual double operator()(double S) const;
    virtual ~PayOffDoubleDigital() {}

  private:
    double LB;
    double UB;
};