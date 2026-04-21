/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Venda {
    string nome;
    int qtd;
    double valor;
    string cidade;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int maxVendas = 10;
    int cont = 0;
    int qtdTotal = 0;
    double arrecadado = 0.0;

    Venda melhor;
    bool temMelhor = false;

    string nome;
    while (cont < maxVendas) {
        if (!getline(cin, nome)) break;
        if (nome.size() && nome.back() == '\r') nome.pop_back();
        if (nome == "encerrar") break;
        if (nome.size() == 0) continue;

        int qtd;
        double valor;
        string cidade;

        if (!(cin >> qtd)) break;
        if (!(cin >> valor)) break;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (!getline(cin, cidade)) break;
        if (cidade.size() && cidade.back() == '\r') cidade.pop_back();

        qtdTotal += qtd;
        arrecadado += valor;

        if (!temMelhor || valor > melhor.valor) {
            melhor = {nome, qtd, valor, cidade};
            temMelhor = true;
        }

        cont++;
        if (cont == maxVendas) break;
    }

    cout << "Quantidade vendida: " << qtdTotal << "\n";
    cout << fixed << setprecision(2);
    cout << "Valor arrecadado: " << arrecadado << "\n";
    if (temMelhor) {
        cout << melhor.nome << "\n" << melhor.cidade;
    }
    return 0;
}