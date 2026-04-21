/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    if (n <= 0) {
        // A matrix of dimension 0 technically satisfies the vacuum condition,
        // but given the problem context, we assume n >= 1.
        return 0;
    }

    vector<double> diag(n);
    vector<double> col_sum(n, 0.0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            double val;
            if (!(cin >> val)) break;
            if (i == j) {
                diag[j] = abs(val);
            } else {
                col_sum[j] += abs(val);
            }
        }
    }

    bool satisfied = true;
    for (int j = 0; j < n; ++j) {
        // According to the Column Criterion, the diagonal element must be non-zero.
        // If it is zero, alpha is effectively infinite, which is not < 1.
        if (diag[j] == 0) {
            satisfied = false;
            break;
        }
        
        double alpha = col_sum[j] / diag[j];
        // The criterion requires max(alpha) < 1.
        // We use a small epsilon only if we expect precision errors to cause 
        // a value like 1.0 to be 1.0000000000000001, but the mathematical 
        // definition is strict.
        if (alpha >= 1.0) {
            satisfied = false;
            break;
        }
    }

    if (satisfied) {
        cout << "SIM" << endl;
    } else {
        cout << "NAO" << endl;
    }

    return 0;
}