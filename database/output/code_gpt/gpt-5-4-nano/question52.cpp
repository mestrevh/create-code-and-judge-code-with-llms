/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    if (!(cin >> n)) return 0;

    vector<long long> ans;
    for (long long p = 2; (1LL << p) <= n; ++p) {
        bool isPrime = true;
        for (long long d = 2; d * d <= p; ++d) {
            if (p % d == 0) { isPrime = false; break; }
        }
        if (!isPrime) continue;

        long long exp = p - 1;
        if (exp < 0) continue;
        unsigned __int128 perfect = (unsigned __int128)1;
        perfect <<= exp;
        perfect *= ((unsigned __int128)1 << p) - 1;

        if (perfect < (unsigned __int128)n) ans.push_back((long long)perfect);
    }

    sort(ans.begin(), ans.end());
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << ans[i] << "\n";
    }
    return 0;
}