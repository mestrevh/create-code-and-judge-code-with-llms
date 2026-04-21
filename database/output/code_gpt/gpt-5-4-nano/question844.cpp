/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int codigo;
    long long quantidade;
    double preco;
    bool hasItem = false;

    int bestCodigo = 0;
    long long bestQtd = 0;
    double bestCusto = 0.0;

    while (cin >> codigo >> quantidade >> preco) {
        if (codigo == 0) break;
        double custo = (double)quantidade * preco;
        if (!hasItem || custo > bestCusto) {
            hasItem = true;
            bestCodigo = codigo;
            bestQtd = quantidade;
            bestCusto = custo;
        }
    }

    if (!hasItem) {
        cout << "nao tem compras";
        return 0;
    }

    cout << fixed << setprecision(2);
    cout << "Item mais caro\n";
    cout << "Codigo: " << bestCodigo << "\n";
    cout << "Quantidade: " << bestQtd << "\n";
    cout << "Custo: " << bestCusto;

    return 0;
}