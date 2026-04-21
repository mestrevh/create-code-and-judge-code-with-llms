/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> vals = a;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        int m = (int)vals.size();
        vector<long long> bit(m + 1, 0);

        auto add = [&](int idx, long long v) {
            for (; idx <= m; idx += idx & -idx) bit[idx] += v;
        };
        auto sum = [&](int idx) -> long long {
            long long r = 0;
            for (; idx > 0; idx -= idx & -idx) r += bit[idx];
            return r;
        };

        long long inv = 0;
        for (int i = 0; i < n; i++) {
            int r = (int)(lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin()) + 1;
            long long leq = sum(r);
            inv += (long long)i - leq;
            add(r, 1);
        }

        cout << inv << "\n";
    }
    return 0;
}