/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; 1LL * i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int qtd;
    while (true) {
        if (!(cin >> qtd)) return 0;
        if (qtd < 2 || qtd > 12) {
            cout << "Informe um valor entre 2 e 12!\n";
        } else break;
    }

    bool first = true;
    for (int i = 0; i < qtd; i++) {
        long long x;
        cin >> x;
        int n = (int)x;
        if (isPrime(n)) {
            if (!first) cout << ' ';
            cout << n;
            first = false;
        }
    }
    return 0;
}