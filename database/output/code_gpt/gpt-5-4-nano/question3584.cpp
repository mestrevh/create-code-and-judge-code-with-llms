/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    if (!(cin >> m >> n)) return 0;

    vector<long long> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];

    auto printVec = [&](const vector<long long>& v) {
        cout << "[";
        for (int i = 0; i < (int)v.size(); i++) {
            cout << v[i];
            if (i + 1 < (int)v.size()) cout << ", ";
        }
        cout << "]";
    };

    for (int pass = 0; pass < n; pass++) {
        for (int i = 0; i < m - 1 - pass; i++) {
            if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
        }
        printVec(a);
        if (pass + 1 < n) cout << "\n";
    }

    return 0;
}