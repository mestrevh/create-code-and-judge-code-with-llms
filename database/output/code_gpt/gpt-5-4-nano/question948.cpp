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

    vector<string> types(n);
    vector<double> need(n, 0.0);

    for (int i = 0; i < n; i++) {
        cin >> types[i];
        if (types[i] == "CIRCULAR") {
            double R;
            cin >> R;
            need[i] = 2.0 * R;
        } else {
            double B, L;
            cin >> B >> L;
            need[i] = hypot(B, L);
        }
    }

    double D;
    cin >> D;

    vector<double> ans;
    for (int i = 0; i < n; i++) {
        if (types[i] == "RETANGULAR") {
            if (need[i] <= D + 1e-12) ans.push_back(need[i]);
        }
    }

    if (ans.empty()) {
        cout << -1 << "\n";
    } else {
        cout.setf(std::ios::fixed);
        cout << setprecision(2);
        for (double x : ans) cout << x + 1e-9 << "\n";
    }

    return 0;
}