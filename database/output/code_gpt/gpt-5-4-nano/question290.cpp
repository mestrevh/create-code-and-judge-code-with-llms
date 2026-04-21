/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long cod1, qtd1;
    long long cod2, qtd2;
    long double val1, val2;

    if (!(cin >> cod1 >> qtd1 >> val1)) return 0;
    cin >> cod2 >> qtd2 >> val2;

    long double total = (long double)qtd1 * val1 + (long double)qtd2 * val2;

    cout << fixed << setprecision(2);
    cout << "VALOR A PAGAR: R$ " << (double)total << "\n";
    return 0;
}