#pragma once
#include <random>
#include <vector>

using namespace std;

vector<double> randNumGen(unsigned long tries) {
    vector<double> randNumVec(tries);

    random_device rd;
    mt19937 gen(rd());
    normal_distribution<> d(0, 1);

    for (unsigned long i = 0; i < tries; i++)
        randNumVec[i] = d(gen);

    return randNumVec;
}