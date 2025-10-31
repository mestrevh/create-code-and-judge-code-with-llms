/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double cotacao, aliquota, valorProduto, valorFrete;
    cin >> cotacao >> aliquota >> valorProduto >> valorFrete;

    double valorProdutoR$ = valorProduto * cotacao;
    double valorFreteR$ = valorFrete * cotacao;
    double valorTotalR$ = valorProdutoR$ + valorFreteR$;
    double impostoImportacao = valorProdutoR$ * 0.6;
    
    double totalImpostos;
    if (valorProduto >= 2500) {
        totalImpostos = impostoImportacao;
    } else {
        totalImpostos = impostoImportacao + valorFreteR__;
    }
    
    double valorFinalProduto = (valorTotalR$ + totalImpostos) / (1 - (aliquota / 100));
    double icms = valorFinalProduto * (aliquota / 100);
    double totalImpostosFinal = totalImpostos + icms;
    double totalAPagar = valorFinalProduto + totalImpostosFinal;

    cout << fixed << setprecision(2);
    cout << cotacao << endl;
    cout << valorProdutoR$ << endl;
    cout << valorFreteR$ << endl;
    cout << valorTotalR$ << endl;
    cout << impostoImportacao << endl;
    cout << icms << endl;
    cout << totalImpostosFinal << endl;
    cout << totalAPagar << endl;
    if (valorProduto >= 2500)
        cout << "Impostos calculados sem o frete" << endl;
    else
        cout << "Impostos calculados com o frete" << endl;

    return 0;
}
