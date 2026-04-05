/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    const int MAXX = 10000000;
    int limit = MAXX;

    vector<int> cnt(limit + 1, 0);
    for (int d = 1; d <= limit; ++d) {
        for (int m = d; m <= limit; m += d) {
            ++cnt[m];
        }
    }

    while (N--) {
        int X;
        cin >> X;
        if (cnt[X] < 4) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}