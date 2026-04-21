/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string command;
    deque<int> fila;

    while (cin >> command && command != "Finalizar") {
        if (command == "Enfileirar") {
            int valor;
            if (cin >> valor) {
                fila.push_back(valor);
            }
        } else if (command == "Desenfileirar") {
            if (!fila.empty()) {
                fila.pop_front();
            }
        } else if (command == "Imprimir") {
            for (size_t i = 0; i < fila.size(); ++i) {
                cout << fila[i] << (i + 1 == fila.size() ? "" : " ");
            }
            cout << "\n";
        }
    }

    return 0;
}