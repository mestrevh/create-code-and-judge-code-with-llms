/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

void toBinary(long long n) {
    if (n >= 2) toBinary(n / 2);
    cout << (n % 2) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    if (!(cin >> N)) return 0;

    if (N == 0) {
        cout << 0 << '\n';
        return 0;
    }

    toBinary(N);
    return 0;
}