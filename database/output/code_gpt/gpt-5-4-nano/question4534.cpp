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

    vector<long long> vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    int m = (int)vals.size();
    vector<long long> bit(m + 1, 0);

    auto add = [&](int idx, long long v) {
        for (; idx <= m; idx += idx & -idx) bit[idx] += v;
    };
    auto sum = [&](int idx) {
        long long s = 0;
        for (; idx > 0; idx -= idx & -idx) s += bit[idx];
        return s;
    };

    long long inv = 0;
    for (int i = 0; i < n; i++) {
        int pos = (int)(lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin()) + 1;
        long long leq = sum(pos);
        inv += (long long)i - leq;
        add(pos, 1);
    }

    cout << inv << "\n";
    return 0;
}