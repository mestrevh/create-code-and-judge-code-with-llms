/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int codigo, quantidade;
    if (!(cin >> codigo)) return 0;
    if (!(cin >> quantidade)) return 0;

    unordered_map<int, double> preco = {
        {1, 5.50},
        {2, 5.50},
        {3, 8.00},
        {4, 2.65}
    };

    double p = preco.count(codigo) ? preco[codigo] : 0.0;
    double total = p * quantidade;

    bool desconto = (quantidade >= 15) || (total >= 40.0);
    if (desconto) total *= 0.85;

    cout.setf(ios::fixed);
    cout << "R$ " << setprecision(2) << total << "\n";
    return 0;
}