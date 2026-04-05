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

    vector<double> best;
    best.reserve(n);
    vector<double> all;
    all.reserve(n);

    double x;
    double curMax = -numeric_limits<double>::infinity();

    for (int i = 0; i < n; i++) {
        cin >> x;
        all.push_back(x);
        curMax = max(curMax, x);
        best.push_back(curMax);
    }

    cout.setf(ios::fixed);
    cout << setprecision(1);

    for (int i = 0; i < n; i++) {
        cout << best[i] << "\n";
    }

    sort(all.begin(), all.end());
    cout.unsetf(ios::floatfield);
    cout << setprecision(10);

    cout << "[";
    for (int i = 0; i < n; i++) {
        if (i) cout << ", ";
        cout << all[i];
    }
    cout << "]";

    return 0;
}