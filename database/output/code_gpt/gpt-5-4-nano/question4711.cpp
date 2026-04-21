/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double reais;
    if (!(cin >> reais)) return 0;

    const long double taxa = 5.75L;
    long double dolares = reais / taxa;

    cout << fixed << setprecision(2);
    cout << "A cotação de R$" << (double)reais << " para dólar é US$" << (double)dolares << "\n";
    return 0;
}