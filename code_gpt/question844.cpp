/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int codigo, quantidade;
    float preco, maiorCusto = 0.0;
    int codigoMaior, quantidadeMaior;
    bool temCompras = false;

    while (true) {
        cin >> codigo >> quantidade >> preco;
        if (codigo == 0) break;
        temCompras = true;
        float custo = quantidade * preco;
        if (custo > maiorCusto) {
            maiorCusto = custo;
            codigoMaior = codigo;
            quantidadeMaior = quantidade;
        }
    }

    if (!temCompras) {
        cout << "nao tem compras" << endl;
    } else {
        cout << "Item mais caro" << endl;
        cout << "Codigo: " << codigoMaior << endl;
        cout << "Quantidade: " << quantidadeMaior << endl;
        cout << "Custo: " << fixed << setprecision(2) << maiorCusto << endl;
    }

    return 0;
}
