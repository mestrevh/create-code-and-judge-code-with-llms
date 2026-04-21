/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double x;
    double total = 0.0;
    long long count = 0;

    cout << "Insira os valores das doacoes:\n";
    while (cin >> x) {
        if (x < 0) break;
        total += x;
        count++;
    }

    double media = (count == 0) ? 0.0 : total / (double)count;

    cout << fixed << setprecision(2);
    cout << "Total arrecadado: " << total << "\n";
    cout << "Valor medio da doacao: " << media << "\n";
    return 0;
}