/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();

    map<string, int> estoque;
    string comando, produto;
    int quantidade;

    for (int i = 0; i < N; ++i) {
        getline(cin, comando);
        getline(cin, produto);
        if (comando == "CADASTRO") {
            if (estoque.find(produto) == estoque.end()) {
                estoque[produto] = 0;
                cout << "Cadastro efetuado com sucesso" << endl;
            } else {
                cout << "Produto ja cadastrado" << endl;
            }
        } else if (comando == "ESTOQUE") {
            cin >> quantidade;
            cin.ignore();
            if (estoque.find(produto) != estoque.end()) {
                estoque[produto] += quantidade;
                cout << "Estoque efetuado com sucesso" << endl;
            } else {
                cout << "Produto nao foi cadastrado" << endl;
            }
        } else if (comando == "VENDA") {
            cin >> quantidade;
            cin.ignore();
            if (estoque.find(produto) != estoque.end()) {
                if (estoque[produto] >= quantidade) {
                    estoque[produto] -= quantidade;
                    cout << "Venda realizada com sucesso" << endl;
                } else {
                    cout << "Nao ha estoque para a venda" << endl;
                }
            } else {
                cout << "Produto nao foi cadastrado" << endl;
            }
        } else {
            cout << "Comando nao reconhecido" << endl;
        }
    }

    for (const auto& p : estoque) {
        cout << p.first << ": " << p.second << endl;
    }

    return 0;
}
