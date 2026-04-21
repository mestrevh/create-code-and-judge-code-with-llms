/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double h, r, custoLata, litrosLata, pintaPorLitro;
    if (!(cin >> h)) return 0;
    cin >> r >> custoLata >> litrosLata >> pintaPorLitro;

    const double area = 2.0 * M_PI * r * (h + r);
    const double totalLitrosNecessarios = area / pintaPorLitro;
    const double quantidadeLatas = ceil(totalLitrosNecessarios / litrosLata);

    const double custoTotal = quantidadeLatas * custoLata;

    cout << fixed << setprecision(6);
    cout << "Quantidade de latas: " << quantidadeLatas << "\n";
    cout << "Custo: R$" << custoTotal << "\n";
    return 0;
}