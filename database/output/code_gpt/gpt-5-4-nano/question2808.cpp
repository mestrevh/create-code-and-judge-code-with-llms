/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long tempo, velocidade;
    cout << "Digite o tempo gasto (em horas) e a velocidade media (em km/h):\n";
    if (!(cin >> tempo >> velocidade)) return 0;

    double distancia = static_cast<double>(tempo) * static_cast<double>(velocidade);
    double litros = distancia / 12.0;

    cout << fixed << setprecision(6);
    cout << "Quantidade de litros gastos na viagem: " << litros << "\n";
    return 0;
}