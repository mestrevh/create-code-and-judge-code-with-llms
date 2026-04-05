/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long i, j;
    if (!(cin >> i >> j)) return 0;
    if (i > j) swap(i, j);

    long long nmax = j;
    int N = (int)nmax;
    vector<long long> sumDiv(N + 1, 0);

    for (int d = 1; d <= N; d++) {
        for (int m = d; m <= N; m += d) {
            sumDiv[m] += d;
        }
    }

    vector<long long> ans;
    for (long long x = i; x <= j; x++) {
        if (sumDiv[(int)x] == x + 1) ans.push_back(x);
    }

    for (size_t k = 0; k < ans.size(); k++) {
        cout << ans[k] << "\n";
    }
    return 0;
}