/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    long double sum = 0.0L;
    long double sumsq = 0.0L;

    for (int i = 0; i < n; i++) {
        long double x;
        cin >> x;
        sum += x;
        sumsq += x * x;
    }

    long double mean = sum / (long double)n;
    long double var = sumsq / (long double)n - mean * mean;
    if (var < 0 && var > -1e-12L) var = 0;

    long double sd = sqrtl(var);

    cout.setf(std::ios::fixed);
    cout << setprecision(2) << (double)sd << "\n";
    return 0;
}