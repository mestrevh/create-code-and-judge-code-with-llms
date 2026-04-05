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
    vector<double> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    double sum = 0.0;
    for (double x : v) sum += x;
    double mean = sum / n;

    double var = 0.0;
    for (double x : v) {
        double d = x - mean;
        var += d * d;
    }
    var /= n;

    cout.setf(std::ios::fixed);
    cout << setprecision(2) << var > 0 ? sqrt(var) : sqrt(var);
    return 0;
}