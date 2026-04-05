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
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long best = a[0] * a[1];
    for (int i = 1; i < n - 1; i++) {
        best = max(best, a[i] * a[i + 1]);
    }

    cout << best;
    return 0;
}