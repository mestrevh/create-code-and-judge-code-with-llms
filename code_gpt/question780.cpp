/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::vector<int> pedidos;
    std::string comando;

    while (std::getline(std::cin, comando)) {
        if (comando[0] == 'a') {
            int pedido = std::stoi(comando.substr(2));
            pedidos.push_back(pedido);
        } else if (comando[0] == 'r') {
            int pedido = std::stoi(comando.substr(2));
            auto it = std::find(pedidos.begin(), pedidos.end(), pedido);
            if (it != pedidos.end()) {
                pedidos.erase(it);
                std::cout << "removido\n";
            } else {
                std::cout << "falha\n";
            }
        } else if (comando[0] == 'p') {
            if (pedidos.empty()) {
                std::cout << "vazia\n";
            } else {
                for (size_t i = 0; i < pedidos.size(); ++i) {
                    std::cout << pedidos[i];
                    if (i != pedidos.size() - 1) std::cout << " ";
                }
                std::cout << "\n";
            }
        }
    }

    return 0;
}
