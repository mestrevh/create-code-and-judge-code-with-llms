/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long apartamentos;
    long double diaria;
    if (!(cin >> apartamentos)) return 0;
    cin >> diaria;

    long double desconto = diaria * 0.75L;
    long double total100 = desconto * (long double)apartamentos * 2.0L;
    long double total70 = desconto * (long double)apartamentos * 0.70L * 2.0L;
    long double totalNormal100 = diaria * (long double)apartamentos * 2.0L;
    long double deixaraArrecadar = totalNormal100 - total100;

    auto round2 = [](long double x) {
        return round(x * 100.0L) / 100.0L;
    };

    cout.setf(std::ios::fixed);
    cout << setprecision(2) << (double)round2(desconto) << "\n";
    cout << setprecision(2) << (double)round2(total100) << "\n";
    cout << setprecision(2) << (double)round2(total70) << "\n";
    cout << setprecision(2) << (double)round2(deixaraArrecadar) << "\n";

    return 0;
}