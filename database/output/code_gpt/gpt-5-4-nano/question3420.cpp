/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    int n;
    if (!(cin >> a >> b >> n)) return 0;

    vector<long long> t(n);
    t[0] = a;
    t[1] = b;

    for (int i = 2; i < n; i++) {
        t[i] = t[i - 1] + t[i - 2];
        if (i % 2 == 1) t[i] = t[i - 1] - t[i - 2];
    }

    for (int i = 0; i < n; i++) {
        cout << t[i] << "\n";
    }
    return 0;
}