/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

// The Pascal triangle table for binomial coefficients
// nCr can reach values up to C(1000, 500) approx 2.7e299, which fits in double.
double C[1001][1001];

void precompute() {
    for (int i = 0; i <= 1000; i++) {
        C[i][0] = 1.0;
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}

int main() {
    // Optimize Standard I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int n;
    double B;
    // Reading n (max users) and B (bandwidth per user)
    if (!(cin >> n >> B)) return 0;

    int bestID = -1;
    double minProb = 2.0; // Probability is always between 0 and 1
    bool found = false;

    int id;
    double p, D;
    // Reading router data until ID is -1
    while (cin >> id >> p >> D && id != -1) {
        double currentProb = 0.0;
        
        // Overload occurs if total bandwidth consumption > router capacity D
        // Let k be the number of active users.
        // Overload if k * B > D  => k > D / B.
        // Smallest integer k that causes overload:
        int k_min = (int)(D / B + 1e-9) + 1;

        if (k_min <= 0) {
            // Even 0 active users cause overload (or D is negative, not expected)
            currentProb = 1.0;
        } else if (k_min <= n) {
            // Sum probabilities for all k from k_min to n
            // P(X=k) = nCr(n, k) * p^k * (1-p)^(n-k)
            for (int k = k_min; k <= n; k++) {
                currentProb += C[n][k] * pow(p, (double)k) * pow(1.0 - p, (double)(n - k));
            }
        } else {
            // Even if all n users are active, capacity is not exceeded
            currentProb = 0.0;
        }

        // Tie-breaking: If multiple routers have the same probability, prefer the first.
        // Using a small epsilon for floating point safety.
        if (!found || currentProb < minProb - 1e-15) {
            minProb = currentProb;
            bestID = id;
            found = true;
        }
    }

    if (found) {
        cout << "O roteador escolhido foi o " << bestID << ", com probabilidade de " << fixed << setprecision(5) << minProb << endl;
    }

    return 0;
}