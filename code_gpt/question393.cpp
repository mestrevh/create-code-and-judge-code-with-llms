/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int pregos, totalPregos = 0;
    const double precoCaixa = 7.89;
    const int pregosPorCaixa = 12;

    while (true) {
        cin >> pregos;
        if (pregos % 2 != 0) break;
        totalPregos += pregos;
    }

    int caixas = totalPregos / pregosPorCaixa;
    int sobras = totalPregos % pregosPorCaixa;
    double totalGasto = caixas * precoCaixa;

    cout << fixed << setprecision(2) << totalGasto << endl;
    cout << sobras << endl;

    return 0;
}
