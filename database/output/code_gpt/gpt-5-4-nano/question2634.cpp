/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double consumo;
    cout << "Digite o consumo de agua em m3:\n";
    if (!(cin >> consumo)) return 0;

    if (consumo < 0) {
        cout << "Numeros negativos nao sao aceitos.";
        return 0;
    }

    long long c = (long long) llround(consumo);
    long long total = 7;

    auto addRange = [&](long long from, long long to, long long price) {
        if (c <= from) return;
        long long hi = min(c, to);
        if (hi > from) total += (hi - from) * price;
    };

    if (c > 10) {
        long long remaining = c - 10;
        long long x;

        x = min(remaining, 20);
        total += x * 1;
        remaining -= x;

        x = min(remaining, 70);
        total += x * 4;
        remaining -= x;

        x = min(remaining, 20);
        total += x * 7;
        remaining -= x;

        if (remaining > 0) total += remaining * 10;
    }

    cout << "O valor a ser pago e de R$ " << total << ".";
    return 0;
}