/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool isPrime(uint64_t n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    if (n % 3 == 0) return n == 3;
    for (uint64_t i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<uint64_t> ms;
    vector<uint64_t> limits;
    uint64_t m;
    while (cin >> m) {
        if ((long long)m < 0) break;
        limits.push_back(m);
    }
    if (limits.empty()) return 0;

    uint64_t maxM = 0;
    for (auto x : limits) maxM = max(maxM, x);

    uint64_t maxNeeded = maxM;
    if (maxNeeded < 2) maxNeeded = 2;

    uint64_t p = 2;
    while (p < maxNeeded) {
        if (isPrime(p)) {
            uint64_t mp = p;
            if (mp < 63) {
                __int128 val = ((__int128)1 << mp) - 1;
                if (val > 0 && val <= numeric_limits<uint64_t>::max()) {
                    uint64_t candidate = (uint64_t)val;
                    if (isPrime(candidate)) ms.push_back(p);
                }
            }
        }
        p++;
    }

    for (size_t i = 0; i < limits.size(); i++) {
        uint64_t lim = limits[i];
        bool first = true;
        for (uint64_t x : ms) {
            if (x >= lim) break;
            if (!first) cout << ' ';
            cout << x;
            first = false;
        }
        if (!first || lim > 0) {
            cout << "\n";
        } else {
            cout << "\n";
        }
    }
    return 0;
}