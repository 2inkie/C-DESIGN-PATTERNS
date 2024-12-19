#pragma once
#include "PayOff3.h"

class PayOffBridge {
  public:
    PayOffBridge(const PayOffBridge &original);
    PayOffBridge(const PayOff &innerPayOff);

    inline double operator()(double S) const;
    ~PayOffBridge();
    PayOffBridge &operator=(const PayOffBridge &original);

  private:
    PayOff *thePayOffPtr;
};

inline double operator()(double S) const { return thePayOffPtr->operator()(S); }