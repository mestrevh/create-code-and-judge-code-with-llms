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

    vector<unsigned long long> V(n), W(n);

    for (int i = 0; i < n; i++) cin >> V[i];

    for (int i = 0; i < n; i++) {
        unsigned long long x = V[i];
        unsigned long long fact = 1;
        for (unsigned long long k = 2; k <= x; k++) fact *= k;
        W[i] = fact;
    }

    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << V[i];
    }
    cout << '\n';

    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << W[i];
    }
    return 0;
}