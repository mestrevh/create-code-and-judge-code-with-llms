/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    map<string, int> estoque;
    
    for (int i = 0; i < n; ++i) {
        string comando;
        getline(cin, comando);

        if (comando != "Registro" && comando != "Venda" && comando != "Recarga") {
            cout << "Comando invalido" << endl;
            continue;
        }

        string produto;
        getline(cin, produto);

        if (comando == "Registro") {
            if (estoque.find(produto) != estoque.end()) {
                cout << "Produto ja registrado" << endl;
            } else {
                estoque[produto] = 0;
                cout << "Produto registrado com sucesso" << endl;
            }
        } else {
            int quantidade;
            cin >> quantidade;
            cin.ignore();

            if (quantidade < 0) {
                cout << "Comando invalido" << endl;
                continue;
            }

            if (comando == "Venda") {
                if (estoque.find(produto) == estoque.end()) {
                    cout << "Produto nao registrado" << endl;
                } else if (estoque[produto] < quantidade) {
                    cout << "Sem estoque para a Venda" << endl;
                } else {
                    estoque[produto] -= quantidade;
                    cout << "Venda realizada com sucesso" << endl;
                }
            } else if (comando == "Recarga") {
                if (estoque.find(produto) == estoque.end()) {
                    cout << "Produto nao registrado" << endl;
                } else {
                    estoque[produto] += quantidade;
                    cout << "Recarga realizada com sucesso" << endl;
                }
            }
        }
    }

    for (const auto& item : estoque) {
        cout << item.first << ": " << item.second << endl;
    }

    return 0;
}
