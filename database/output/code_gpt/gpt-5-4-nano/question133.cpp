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
    while (cin >> n) {
        if (n == 0) break;
        unordered_map<long long, long long> bal;
        bal.reserve((size_t)n * 2 + 1);
        for (int i = 0; i < n; i++) {
            long long a, b;
            cin >> a >> b;
            bal[a]--;
            bal[b]++;
        }
        bool ok = true;
        for (const auto &p : bal) {
            if (p.second != 0) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}