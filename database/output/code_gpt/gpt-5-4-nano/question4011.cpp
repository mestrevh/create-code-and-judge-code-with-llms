/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b, c, nulos;
    if (!(cin >> a)) return 0;
    cin >> b >> c >> nulos;

    double total = a + b + c + nulos;
    auto pct = [&](double x) -> double {
        if (total == 0.0) return 0.0;
        return (x * 100.0) / total;
    };

    cout << fixed << setprecision(3);
    cout << "Digite a quantidade de votos do candidato A:\n";
    cout << "Digite a quantidade de votos do candidato B:\n";
    cout << "Digite a quantidade de votos do candidato C:\n";
    cout << "Digite a quantidade de votos nulos:\n";
    cout << "Candidato A: " << pct(a) << " %\n";
    cout << "Candidato B: " << pct(b) << " %\n";
    cout << "Candidato C: " << pct(c) << " %\n";
    cout << "Votos Nulos: " << pct(nulos) << " %\n";

    return 0;
}