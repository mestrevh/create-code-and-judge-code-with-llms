/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<pair<string, int>> pessoas;
    string nome;
    int id;

    while (cin >> nome >> id) {
        pessoas.push_back({nome, id});
    }

    while (!pessoas.empty()) {
        auto atual = pessoas.front();
        pessoas.erase(pessoas.begin());
        bool encontrado = false;

        for (size_t i = 0; i < pessoas.size(); ++i) {
            if (pessoas[i].second == atual.second) {
                cout << atual.first << " seu parceiro esta na posicao " << i + 1 << " e o seu nome e " << pessoas[i].first << ".\n";
                pessoas.erase(pessoas.begin() + i);
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            cout << atual.first << " nao existe um parceiro para voce.\n";
        }
    }

    return 0;
}
