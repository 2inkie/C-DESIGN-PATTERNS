#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <fstream>

// Function to simulate a GBM path
std::vector<double> simulateGBM(double S0, double mu, double sigma, double T, int N) {
    std::vector<double> S(N + 1);
    S[0] = S0;
    double dt = T / N;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0.0, 1.0);

    for (int i = 1; i <= N; ++i) {
        double Z = d(gen);
        S[i] = S[i - 1] * std::exp((mu - 0.5 * sigma * sigma) * dt + sigma * std::sqrt(dt) * Z);
    }

    return S;
}

int main() {
    // Parameters
    double S0 = 100.0; // Initial stock price
    double mu = 0.1; // Drift coefficient
    double sigma = 0.2; // Volatility coefficient
    double T = 1.0; // Time horizon (in years)
    int N = 252; // Number of time steps (e.g., trading days in a year)

    // Simulate GBM
    std::vector<double> S = simulateGBM(S0, mu, sigma, T, N);

    // Output results to a file for plotting
    std::ofstream outFile("gbm_simulation.csv");
    outFile << "Time,Stock Price\n";
    for (int i = 0; i <= N; ++i) {
        outFile << i * (T / N) << "," << S[i] << "\n";
    }
    outFile.close();

    std::cout << "GBM simulation completed and saved to gbm_simulation.csv" << std::endl;

    return 0;
}