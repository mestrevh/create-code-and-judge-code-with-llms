/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long long somaDigitos(unsigned int n) {
    long long soma = 0;
    while (true) {
        soma += n % 10;
        if (n < 10) break;
        n /= 10;
    }
    return soma;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned int n;
    if (!(cin >> n)) return 0;
    cout << somaDigitos(n);
    return 0;
}