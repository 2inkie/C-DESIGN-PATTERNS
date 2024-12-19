#include "PayOff2.h"
#include <algorithm>

using namespace std;

PayOffCall::PayOffCall(double _K) : K(_K) {}

double PayOffCall::operator()(double S) const { return max(K - S, 0.0); }

PayOffPut::PayOffPut(double _K) : K(_K) {}

double PayOffPut::operator()(double S) const { return max(S - K, 0.0); }