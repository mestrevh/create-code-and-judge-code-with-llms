/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::queue<int> fila;
    std::string comando;

    while (std::cin >> comando) {
        if (comando == "Finalizar") {
            break;
        }

        if (comando == "Enfileirar") {
            int valor;
            std::cin >> valor;
            fila.push(valor);
        } else if (comando == "Desenfileirar") {
            if (!fila.empty()) {
                fila.pop();
            }
        } else if (comando == "Imprimir") {
            if (fila.empty()) {
                std::cout << '\n';
            } else {
                std::queue<int> temp_fila = fila;
                bool primeiro = true;
                while (!temp_fila.empty()) {
                    if (!primeiro) {
                        std::cout << " ";
                    }
                    std::cout << temp_fila.front();
                    temp_fila.pop();
                    primeiro = false;
                }
                std::cout << '\n';
            }
        }
    }

    return 0;
}
