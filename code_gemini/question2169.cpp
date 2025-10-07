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

    std::vector<int> pedidos;
    char command;

    while (std::cin >> command && command != 's') {
        if (command == 'a') {
            int pedido_id;
            std::cin >> pedido_id;
            pedidos.push_back(pedido_id);
        } else if (command == 'r') {
            int pedido_id;
            std::cin >> pedido_id;
            auto it = std::find(pedidos.begin(), pedidos.end(), pedido_id);
            if (it != pedidos.end()) {
                pedidos.erase(it);
                std::cout << "removido\n";
            } else {
                std::cout << "falha\n";
            }
        } else if (command == 'p') {
            if (pedidos.empty()) {
                std::cout << "vazia\n";
            } else {
                for (size_t i = 0; i < pedidos.size(); ++i) {
                    std::cout << pedidos[i] << (i == pedidos.size() - 1 ? "" : " ");
                }
                std::cout << "\n";
            }
        }
    }

    return 0;
}
