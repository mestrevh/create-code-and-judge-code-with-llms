/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string sabor;
    int bolas;
    if (!(cin >> ws, getline(cin, sabor))) return 0;
    if (!(cin >> bolas)) return 0;

    string s = sabor;
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return tolower(c); });

    double preco = 0.0;

    if (s == "morango" || s == "cereja") preco = 4.50;
    else if (s == "damasco" || s == "siriguela") preco = 3.80;
    else preco = 2.75;

    double total = preco * bolas;

    cout << fixed << setprecision(2) << total << "\n";
    if (bolas > 2) cout << "COM CALDA\n";
    else cout << "SEM CALDA\n";

    return 0;
}