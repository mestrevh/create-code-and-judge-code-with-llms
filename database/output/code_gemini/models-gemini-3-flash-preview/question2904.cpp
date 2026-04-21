/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double C_double;
    int N;
    if (!(cin >> C_double >> N)) return 0;

    vector<long long> X(N);
    for (int i = 0; i < N; ++i) {
        double val;
        cin >> val;
        X[i] = (long long)round(val * 100.0);
    }

    vector<int> L(N), R(N);
    stack<int> s;

    for (int i = 0; i < N; ++i) {
        while (!s.empty() && X[s.top()] >= X[i]) {
            s.pop();
        }
        if (s.empty()) {
            L[i] = 0;
        } else {
            L[i] = s.top() + 1;
        }
        s.push(i);
    }

    while (!s.empty()) s.pop();

    for (int i = N - 1; i >= 0; --i) {
        while (!s.empty() && X[s.top()] >= X[i]) {
            s.pop();
        }
        if (s.empty()) {
            R[i] = N - 1;
        } else {
            R[i] = s.top() - 1;
        }
        s.push(i);
    }

    long long max_prod = 0;
    for (int i = 0; i < N; ++i) {
        long long current_prod = X[i] * (long long)(R[i] - L[i] + 1);
        if (current_prod > max_prod) {
            max_prod = current_prod;
        }
    }

    double final_profit = ((double)max_prod * C_double) / 10000.0;

    cout << fixed << setprecision(2) << final_profit << "\n";

    return 0;
}

