/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float fatura;
    cin >> fatura;

    float aPagarMarço = fatura / 2;
    float aPagarAbril = (fatura / 2) * 1.065;

    cout << fixed << setprecision(2);
    cout << "Valor total da fatura: R$ " << fatura << endl;
    cout << "Valor a pagar em Marco: R$ " << aPagarMarço << endl;
    cout << "Valor a pagar em Abril: R$ " << aPagarAbril << endl;

    return 0;
}
