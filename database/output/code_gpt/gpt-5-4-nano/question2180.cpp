/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    for (int tc = 1; tc <= T; tc++) {
        int n;
        cin >> n;
        vector<long long> r(n);
        for (int i = 0; i < n; i++) cin >> r[i];

        vector<long long> H;
        H.reserve(n + 1);
        H.push_back(0);
        for (int i = 0; i < n; i++) H.push_back(r[i]);

        auto can = [&](long long k0) -> bool {
            long long k = k0;
            for (int i = 0; i < n; i++) {
                long long d = H[i + 1] - H[i];
                if (d > k) return false;
                if (d == k) k--;
            }
            return true;
        };

        long long lo = 0, hi = 1000000000000000LL;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (can(mid)) hi = mid;
            else lo = mid + 1;
        }

        cout << "Case " << tc << ": " << lo << "\n";
    }
    return 0;
}