/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> pilha;
    std::string comando;

    while (std::cin >> comando && comando != "Finalizar") {
        if (comando == "Empilhar") {
            int valor;
            std::cin >> valor;
            pilha.push_back(valor);
        } else if (comando == "Desempilhar") {
            if (!pilha.empty()) {
                pilha.pop_back();
            }
        } else if (comando == "Imprimir") {
            if (!pilha.empty()) {
                for (int i = pilha.size() - 1; i >= 0; --i) {
                    std::cout << pilha[i] << (i == 0 ? "" : " ");
                }
            }
            std::cout << "\n";
        }
    }

    return 0;
}
