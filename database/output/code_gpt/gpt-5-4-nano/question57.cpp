/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<double> a;
    double x;
    while (cin >> x) {
        if (x == -1) break;
        a.push_back(x);
    }

    int n = (int)a.size();
    if (n == 0) return 0;

    long double sum = 0;
    for (double v : a) sum += v;
    long double mean = sum / n;

    long double var = 0;
    for (double v : a) {
        long double d = v - mean;
        var += d * d;
    }
    var /= n;
    long double sd = sqrt(var);

    int cnt = 0;
    for (double v : a) if ((long double)v > mean) cnt++;

    cout.setf(std::ios::fixed);
    cout << setprecision(2) << (double)mean << "\n";
    cout << setprecision(2) << (double)sd << "\n";
    cout << cnt << "\n";

    return 0;
}