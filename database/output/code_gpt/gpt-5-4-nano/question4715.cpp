/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

void sequencia_aritmetica(long long a, long long r, long long n) {
    for (long long i = 0; i < n; i++) {
        long long term = a + i * r;
        cout << term;
        if (i + 1 < n) cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, r, n;
    if (!(cin >> a)) return 0;
    cin >> r >> n;

    sequencia_aritmetica(a, r, n);
    return 0;
}