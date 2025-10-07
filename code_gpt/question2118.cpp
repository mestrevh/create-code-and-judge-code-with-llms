/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> estoque;
    string comando, produto;
    int quantidade;

    while (n--) {
        cin >> comando;
        if (comando == "CADASTRO") {
            cin.ignore();
            getline(cin, produto);
            if (estoque.find(produto) == estoque.end()) {
                estoque[produto] = 0;
                cout << "Produto cadastrado com sucesso" << endl;
            } else {
                cout << "Produto já cadastrado" << endl;
            }
        } else if (comando == "ESTOQUE") {
            cin.ignore();
            getline(cin, produto);
            cin >> quantidade;
            if (quantidade < 0) {
                cout << "Comando inválido" << endl;
                continue;
            }
            if (estoque.find(produto) != estoque.end()) {
                estoque[produto] += quantidade;
                cout << "Estoque realizado com sucesso" << endl;
            } else {
                cout << "Produto não foi cadastrado" << endl;
            }
        } else if (comando == "VENDA") {
            cin.ignore();
            getline(cin, produto);
            cin >> quantidade;
            if (quantidade < 0) {
                cout << "Comando inválido" << endl;
                continue;
            }
            if (estoque.find(produto) != estoque.end()) {
                if (estoque[produto] >= quantidade) {
                    estoque[produto] -= quantidade;
                    cout << "Venda realizada com sucesso" << endl;
                } else {
                    cout << "Não há estoque para a venda" << endl;
                }
            } else {
                cout << "Produto não foi cadastrado" << endl;
            }
        } else {
            cout << "Comando inválido" << endl;
        }
    }

    for (const auto& item : estoque) {
        cout << item.first << ": " << item.second << endl;
    }

    return 0;
}
