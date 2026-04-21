/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<long long> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    auto can = [&](long long r) -> bool {
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < m && b[j] + r < a[i]) j++;
            if (j == m) return false;
            if (llabs(b[j] - a[i]) > r) {
                if (j + 1 < m && llabs(b[j + 1] - a[i]) <= r) {
                    j++;
                } else {
                    return false;
                }
            }
        }
        return true;
    };

    long long low = 0, high = 2000000000LL;
    while (low < high) {
        long long mid = low + (high - low) / 2;
        if (can(mid)) high = mid;
        else low = mid + 1;
    }

    cout << low << "\n";
    return 0;
}