/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<double> temps;
    double x;
    while (cin >> x) temps.push_back(x);

    if (temps.empty()) return 0;

    vector<double> neg;
    double mn = 1e100;
    for (double v : temps) {
        if (v < 0) neg.push_back(v);
        mn = min(mn, v);
    }

    double sum = 0.0;
    for (double v : neg) sum += v;

    double avg = neg.empty() ? 0.0 : sum / neg.size();

    cout.setf(std::ios::fixed);
    cout << setprecision(2) << avg << "\n" << setprecision(2) << mn << "\n";
    return 0;
}