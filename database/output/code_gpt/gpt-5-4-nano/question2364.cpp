/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long M;
    if (!(cin >> M)) return 0;

    const long long TARGET = 10000000LL;
    if (M >= TARGET) {
        cout << 1 << " pessoas precisam assistir ao jogo.";
        return 0;
    }

    long long x = 2;
    while (true) {
        __int128 f = 0;
        if (x % 2 == 0) {
            long long k = x / 2;
            f = (__int128)k * (2 * M + (2 * k - 1));
        } else {
            long long k = (x - 1) / 2;
            f = (__int128)k * (2 * M + (2 * k + 1)) + M + (2 * k + 1);
        }
        if (f >= TARGET) {
            cout << x << " pessoas precisam assistir ao jogo.";
            return 0;
        }
        x++;
    }
    return 0;
}