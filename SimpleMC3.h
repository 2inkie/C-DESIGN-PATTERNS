#pragma once
#include "Vanilla1.h"

double SimpleMonteCarlo3(const VanillaOption &theOption, double S, double vol,
                         double r, unsigned long tries);