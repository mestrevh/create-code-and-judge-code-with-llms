/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    long long bestD = 0, bestP = 0;
    bool bestSet = false;
    long long rule1D = 0, rule1P = 0;
    bool foundRule1 = false;

    for (int i = 1; i <= N; ++i) {
        long long D, P;
        if (!(cin >> D >> P)) break;

        // Rule 1: If condition met, Ash stops investigating and picks this method.
        // Rule 1 is checked for the current book immediately after analysis.
        if (!foundRule1) {
            if (D + P < (long long)N - i) {
                rule1D = D;
                rule1P = P;
                foundRule1 = true;
            }
        }

        // Rule 2: Ash keeps track of the best method as a fallback if Rule 1 is never met.
        if (!bestSet) {
            bestP = P;
            bestD = D;
            bestSet = true;
        } else {
            if (P < bestP) {
                bestP = P;
                bestD = D;
            } else if (P == bestP) {
                if (D < bestD) {
                    bestD = D;
                }
                // If P and D are same, the first one found is kept (no update).
            }
        }
    }

    if (foundRule1) {
        cout << rule1D << " " << rule1P << "\n";
    } else if (bestSet) {
        cout << bestD << " " << bestP << "\n";
    }

    return 0;
}