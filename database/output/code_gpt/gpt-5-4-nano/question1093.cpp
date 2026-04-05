/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int idade;
    double valor;
    char tipo;
    char cont;

    int qtd = 0;
    double totalVista = 0.0, totalCartao = 0.0;
    int menorIdade = INT_MAX;
    double maiorCompra = -1.0;
    double somaVista = 0.0;
    int qtdVista = 0;

    while (true) {
        if (!(cin >> idade)) return 0;
        if (!(cin >> valor)) return 0;
        if (!(cin >> tipo)) return 0;
        if (!(cin >> cont)) return 0;

        qtd++;
        if (valor > maiorCompra) maiorCompra = valor;
        menorIdade = min(menorIdade, idade);

        if (tipo == 'V') {
            totalVista += valor;
            somaVista += valor;
            qtdVista++;
        } else {
            totalCartao += valor;
        }

        if (cont == 'N') break;
    }

    double mediaVista = 0.0;
    if (qtdVista > 0) mediaVista = somaVista / qtdVista;

    cout << qtd << "\n";
    cout << fixed << setprecision(2) << totalVista << "\n";
    cout << fixed << setprecision(2) << totalCartao << "\n";
    cout << menorIdade << "\n";
    cout << fixed << setprecision(2) << maiorCompra << "\n";
    cout << fixed << setprecision(2) << mediaVista << "\n";

    return 0;
}