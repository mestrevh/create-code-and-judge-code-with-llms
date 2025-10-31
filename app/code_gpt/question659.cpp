/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

double calculateProbability(int ev1, int ev2, int at, int d, vector<vector<double>>& dp) {
    if (ev1 <= 0) return 0.0;
    if (ev2 <= 0) return 1.0;
    if (dp[ev1][ev2] >= 0) return dp[ev1][ev2];

    double winProb = 0.0;
    for (int roll = 1; roll <= 6; ++roll) {
        if (roll <= at) {
            winProb += calculateProbability(ev1 + d, ev2 - d, at, d, dp) / 6.0;
        } else {
            winProb += calculateProbability(ev1 - d, ev2 + d, at, d, dp) / 6.0;
        }
    }
    return dp[ev1][ev2] = winProb;
}

int main() {
    int ev1, ev2, at, d;
    while (true) {
        cin >> ev1 >> ev2 >> at >> d;
        if (ev1 == 0 && ev2 == 0 && at == 0 && d == 0) break;

        vector<vector<double>> dp(11, vector<double>(11, -1));
        double prob = calculateProbability(ev1, ev2, at, d, dp) * 100;
        cout << fixed << setprecision(1) << prob << endl;
    }
    return 0;
}
