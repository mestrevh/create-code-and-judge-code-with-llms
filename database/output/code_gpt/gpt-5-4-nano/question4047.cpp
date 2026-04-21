/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> v;
    long long x;
    while (cin >> x) v.push_back(x);
    if (v.empty()) return 0;

    int n = (int)v.size();
    vector<long long> inv(n), parimp(n);

    for (int i = 0; i < n; i++) inv[i] = v[n - 1 - i];

    int k = 0;
    for (int i = 0; i < n; i++) if (i % 2 == 0) parimp[k++] = v[i];
    for (int i = 0; i < n; i++) if (i % 2 == 1) parimp[k++] = v[i];

    cout << "Invert:";
    for (int i = 0; i < n; i++) {
        if (i == 0) cout << ' ';
        else cout << ' ';
        cout << inv[i];
    }
    cout << "\n";

    cout << "ParImp:";
    for (int i = 0; i < n; i++) {
        cout << ' ' << parimp[i];
    }
    cout << "\n";

    cout << "Soma:";
    for (int i = 0; i < n; i++) {
        long long s = inv[i] + parimp[i];
        cout << ' ' << s;
    }
    cout << "\n";

    return 0;
}