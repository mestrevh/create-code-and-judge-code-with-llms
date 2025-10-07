/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> fila;
    char command;

    while (std::cin >> command) {
        if (command == 'a') {
            int pedido;
            std::cin >> pedido;
            fila.push_back(pedido);
        } else if (command == 'r') {
            int pedido;
            std::cin >> pedido;
            auto it = std::find(fila.begin(), fila.end(), pedido);
            if (it != fila.end()) {
                fila.erase(it);
                std::cout << "removido\n";
            } else {
                std::cout << "falha\n";
            }
        } else if (command == 'p') {
            if (fila.empty()) {
                std::cout << "vazia\n";
            } else {
                for (size_t i = 0; i < fila.size(); ++i) {
                    std::cout << fila[i] << (i == fila.size() - 1 ? "" : " ");
                }
                std::cout << "\n";
            }
        }
    }

    return 0;
}
