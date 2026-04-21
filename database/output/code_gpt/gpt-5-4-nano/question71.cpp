/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<int, long long> estoque;
    int n, m;
    while (cin >> n >> m) {
        if (n == 9999) break;
        estoque[n] = m;
    }

    int i, j;
    long long k;
    while (cin >> i >> j >> k) {
        if (i == 9999) break;

        auto it = estoque.find(j);
        long long disp = (it == estoque.end() ? 0LL : it->second);

        if (disp >= k) {
            cout << "OK\n";
            if (it != estoque.end()) it->second -= k;
        } else {
            cout << "ESTOQUE INSUFICIENTE\n";
        }
    }

    for (auto &p : estoque) {
        cout << p.first << ' ' << p.second << '\n';
    }
    return 0;
}