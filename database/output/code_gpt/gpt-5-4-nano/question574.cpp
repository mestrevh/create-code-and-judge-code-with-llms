/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double cotacao, aliquotaPercent, valorProduto, valorFrete;
    if (!(cin >> cotacao)) return 0;
    cin >> aliquotaPercent >> valorProduto >> valorFrete;

    double aliquota = aliquotaPercent / 100.0;

    double produtoReais = valorProduto * cotacao;
    double freteReais = valorFrete * cotacao;

    bool isento = valorProduto >= 2500.0;
    string isentoTexto = isento ? "Impostos calculados sem o frete" : "Impostos calculados com o frete";

    double baseParaImpostos;
    if (isento) baseParaImpostos = produtoReais + freteReais * 0.0;
    else baseParaImpostos = produtoReais + freteReais;

    double impostoImportacao = 0.60 * baseParaImpostos;

    double valorFinalProduto = (produtoReais + baseParaImpostos + impostoImportacao) / (1.0 - aliquota);

    double icms = valorFinalProduto * aliquota;
    double totalImpostos = impostoImportacao + icms;

    double totalPagar = produtoReais + freteReais + totalImpostos;
    double total = produtoReais + freteReais;

    cout.setf(ios::fixed);
    cout << setprecision(2);

    cout << cotacao << "\n";
    cout << produtoReais << "\n";
    cout << freteReais << "\n";
    cout << total << "\n";
    cout << impostoImportacao << "\n";
    cout << icms << "\n";
    cout << totalImpostos << "\n";
    cout << totalPagar << "\n";
    cout << isentoTexto;

    return 0;
}