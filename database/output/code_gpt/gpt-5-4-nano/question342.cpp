/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    if (!(cin >> N)) return 0;

    long long n = N;
    long long x = llabs(n);

    long long countDiv = 0;
    for (long long d = 1; d * d <= x; d++) {
        if (x % d == 0) {
            long long d1 = d;
            long long d2 = x / d;

            if (d1 % 3 == 0) countDiv++;
            if (d2 != d1 && d2 % 3 == 0) countDiv++;
        }
    }

    if (countDiv == 0) {
        cout << "O numero nao possui divisores multiplos de 3!\n";
    } else {
        cout << countDiv << "\n";
    }
    return 0;
}