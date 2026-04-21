/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long n;
    if (!(cin >> n)) return 0;

    for (unsigned long long a = 1; a <= 2'000'000; ++a) {
        __int128 t = (__int128)a * (a + 1) * (a + 2);
        if (t == (__int128)n) {
            cout << a << " * " << (a + 1) << " * " << (a + 2) << " = " << n << "\n";
            cout << "Verdadeiro";
            return 0;
        }
        if (t > (__int128)n) break;
    }

    cout << "Falso";
    return 0;
}