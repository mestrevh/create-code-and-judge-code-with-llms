/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> pilha;
    string comando;

    while (cin >> comando && comando != "Finalizar") {
        if (comando == "Empilhar") {
            int valor;
            cin >> valor;
            pilha.push_back(valor);
        } else if (comando == "Desempilhar") {
            if (!pilha.empty()) {
                pilha.pop_back();
            }
        } else if (comando == "Imprimir") {
            if (!pilha.empty()) {
                for (int i = (int)pilha.size() - 1; i >= 0; --i) {
                    cout << pilha[i] << (i == 0 ? "" : " ");
                }
                cout << "\n";
            } else {
                cout << "\n";
            }
        }
    }

    return 0;
}