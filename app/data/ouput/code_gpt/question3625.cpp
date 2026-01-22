/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Personagem {
    string nome;
    int vida;
};

int main() {
    int n;
    cin >> n;
    vector<Personagem> personagens(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> personagens[i].nome >> personagens[i].vida;
    }

    int indice, valor;
    while (true) {
        cin >> indice;
        if (indice == -1) break;

        if (indice < 0 || indice >= n) {
            cout << "Índice inválido" << endl;
            continue;
        }

        cin >> valor;
        personagens[indice].vida += valor;

        for (const auto& p : personagens) {
            cout << p.nome << " = " << p.vida << endl;
        }
    }

    return 0;
}
