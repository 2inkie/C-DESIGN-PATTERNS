#include "PayOff3.h"
#include <algorithm>

PayOffCall ::PayOffCall(double _K) : K(_K) {}
double PayOffCall::operator()(double S) const { return std::max(S - K, 0.0); }

PayOff *PayOffCall::clone() const { return new PayOffCall(*this); }

PayOffPut ::PayOffPut(double _K) : K(_K) {}
double PayOffPut::operator()(double S) const { return std::max(K - S, 0.0); }

PayOff *PayOffPut::clone() const { return new PayOffPut(*this); }