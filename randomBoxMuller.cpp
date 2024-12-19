#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

const double pi = 3.14159265358979323846;

vector<double> RandNorms(unsigned long tries) {
    vector<double> randNormNums(tries);

    int j = tries;

    for (int i = 0; i < tries / 2; i++) {
        double X1 = double(rand()) / RAND_MAX;
        double X2 = double(rand()) / RAND_MAX;

        double R = sqrt(-2 * log(X1));
        double Theta = 2 * pi * X2;

        double Y1 = R * cos(Theta);
        double Y2 = R * sin(Theta);

        randNormNums[i] = Y1;
        randNormNums[j] = Y2;
        j--;
    }

    return randNormNums;
}

int main() { return 0; }