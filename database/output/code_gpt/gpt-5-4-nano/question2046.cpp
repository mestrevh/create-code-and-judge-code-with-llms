/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

bool eh_primo(long long x) {
    if (x < 2) return false;
    if (x % 2 == 0) return x == 2;
    if (x % 3 == 0) return x == 3;
    for (long long i = 5; i * i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) return false;
    }
    return true;
}

long long proximo_primo(long long y) {
    if (y <= 2) return 2;
    long long x = y;
    if (x % 2 == 0) x++;
    while (!eh_primo(x)) x += 2;
    return x;
}

long double fatorial(int z) {
    long double r = 1.0L;
    for (int i = 2; i <= z; i++) r *= (long double)i;
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    long double soma = 0.0L;
    vector<string> termos;
    termos.reserve(n);

    for (int k = 1; k <= n; k++) {
        long double fat = fatorial(k);
        long long den;
        if (k == 1) den = 1;
        else den = proximo_primo((long long)k);

        long double termo = fat / (long double)den;
        soma += termo;
        termos.push_back(to_string(k) + "!/" + to_string(den));
    }

    for (int i = 0; i < (int)termos.size(); i++) {
        if (i) cout << " + ";
        cout << termos[i];
    }
    cout << "\n" << fixed << setprecision(2) << (double)soma << "\n";
    return 0;
}