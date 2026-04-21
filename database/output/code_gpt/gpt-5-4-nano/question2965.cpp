/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double area;
    if (!(cin >> area)) return 0;

    const double cover = 7.0;
    const double litros1 = 24.0, preco1 = 91.0;
    const double litros2 = 5.4, preco2 = 23.0;

    auto round2 = [](double x) {
        return floor(x * 100.0 + 0.5) / 100.0;
    };

    double litrosNec = area / cover;

    long long n1 = (long long)ceil(litrosNec / litros1);
    double cost1 = round2(n1 * preco1);

    long long n2 = (long long)ceil(litrosNec / litros2);
    double cost2 = round2(n2 * preco2);

    long long buy1 = (long long)floor(litrosNec / litros1);
    if (buy1 < 0) buy1 = 0;
    double remaining = litrosNec - buy1 * litros1;
    long long buy2 = 0;
    double cost3 = 0.0;
    if (remaining > 1e-12) {
        buy2 = (long long)ceil(remaining / litros2);
        cost3 = round2(buy1 * preco1 + buy2 * preco2);
    } else {
        buy2 = 0;
        cost3 = round2(buy1 * preco1);
    }

    cout << fixed << setprecision(2);

    cout << "a) " << n1 << " lata(s) de 24 litros: R$ " << cost1 << "\n";
    cout << "b) " << n2 << " lata(s) de 5.4 litros: R$ " << cost2 << "\n";
    cout << "c) " << buy1 << " lata(s) de 24 litros e " << buy2 << " lata(s) de 5.4 litros: R$ " << cost3;

    return 0;
}