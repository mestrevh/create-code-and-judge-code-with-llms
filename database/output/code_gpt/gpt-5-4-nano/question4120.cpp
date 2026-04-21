/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double valor;
    cout << "Digite o valor total do produto: ";
    if (!(cin >> valor)) return 0;

    double desconto = valor * 0.10;
    double totalDesconto = valor - desconto;

    double parcela = totalDesconto / 3.0;

    double comissaoVista = totalDesconto * 0.05;
    double comissaoPrazo = valor * 0.05;

    cout << fixed << setprecision(2);
    cout << "A vista com desconto de 10%: " << totalDesconto << "\n";
    cout << "Valor da parcela em 3x sem juros: " << parcela << "\n";
    cout << "Comissao do vendedor a vista: " << comissaoVista << "\n";
    cout << "Comissao do vendedor a prazo: " << comissaoPrazo << "\n";

    return 0;
}