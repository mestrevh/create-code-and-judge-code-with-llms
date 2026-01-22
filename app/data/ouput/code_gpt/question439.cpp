/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int jogosVendidos;
    cin >> jogosVendidos;

    double precoJogo = 19.90;
    double salarioPorcentagem = 0.50;
    double bonusPorcentagem = 0.08;
    int bonusThreshold = 15;

    double valorTotalVendas = jogosVendidos * precoJogo;
    double salario = valorTotalVendas * salarioPorcentagem;
    double bonus = (jogosVendidos / bonusThreshold) * bonusPorcentagem * valorTotalVendas;

    double totalReceber = salario + bonus;

    cout << fixed << setprecision(2);
    cout << valorTotalVendas << endl;
    cout << bonus << endl;
    cout << totalReceber << endl;

    return 0;
}
