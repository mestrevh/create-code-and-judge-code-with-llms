/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int volume;
    int n;
    if (!(cin >> volume)) return 0;
    while (volume < 0 || volume > 100) {
        if (!(cin >> volume)) return 0;
    }

    if (!(cin >> n)) return 0;
    while (n < 0 || n > 10) {
        if (!(cin >> n)) return 0;
    }

    for (int i = 0; i < n; i++) {
        int delta;
        if (!(cin >> delta)) return 0;
        long long nv = (long long)volume + delta;
        if (nv > 100) nv = 100;
        if (nv < 0) nv = 0;
        volume = (int)nv;
    }

    cout << volume << "\n";
    return 0;
}