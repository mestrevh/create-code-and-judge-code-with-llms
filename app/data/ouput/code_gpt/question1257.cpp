/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    cin >> N;
    unordered_map<string, int> estoque;
    string comando, produto;
    int quantidade;

    while (N--) {
        cin >> comando;
        if (comando == "CADASTRO") {
            cin.ignore();
            getline(cin, produto);
            if (estoque.find(produto) == estoque.end()) {
                estoque[produto] = 0;
                cout << "Produto cadastrado com sucesso\n";
            } else {
                cout << "Produto ja cadastrado\n";
            }
        } else if (comando == "ESTOQUE") {
            cin.ignore();
            getline(cin, produto);
            cin >> quantidade;
            if (estoque.find(produto) != estoque.end()) {
                estoque[produto] += quantidade;
                cout << "Estoque realizado com sucesso\n";
            } else {
                cout << "Produto nao foi cadastrado\n";
            }
        } else if (comando == "VENDA") {
            cin.ignore();
            getline(cin, produto);
            cin >> quantidade;
            if (estoque.find(produto) != estoque.end()) {
                if (estoque[produto] >= quantidade) {
                    estoque[produto] -= quantidade;
                    cout << "Venda realizada com sucesso\n";
                } else {
                    cout << "Nao ha estoque para a venda\n";
                }
            } else {
                cout << "Produto nao foi cadastrado\n";
            }
        } else {
            cout << "Comando invalido\n";
        }
    }

    for (const auto& item : estoque) {
        cout << item.first << ": " << item.second << "\n";
    }

    return 0;
}
