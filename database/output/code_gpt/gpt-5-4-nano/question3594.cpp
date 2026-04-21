/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool isPrime(long long n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    if (n % 3 == 0) return n == 3;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    if (!(cin >> a)) return 0;

    while (true) {
        if (!(cin >> b)) return 0;
        if (b > a) break;
        cout << "Digite um valor maior que o primeiro!";
        if (cin.eof()) return 0;
    }

    long long sum = 0;
    bool any = false;
    for (long long x = a; x <= b; ++x) {
        if (isPrime(x)) {
            sum += x;
            any = true;
        }
    }

    if (!any) cout << "Sem numeros primos no intervalo informado.";
    else cout << sum;

    return 0;
}