/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double valorProduto;
    int anosGarantia;
    cin >> valorProduto >> anosGarantia;

    double valorTotal = valorProduto;

    if (anosGarantia == 1) {
        valorTotal += valorProduto * 0.03;
    } else if (anosGarantia == 2) {
        valorTotal += valorProduto * 0.05;
    }

    cout << fixed << setprecision(2) << valorTotal << endl;

    return 0;
}
