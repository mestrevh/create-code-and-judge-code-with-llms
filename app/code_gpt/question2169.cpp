/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <set>
#include <sstream>

int main() {
    std::set<int> pedidos;
    std::string linha;

    while (std::getline(std::cin, linha)) {
        if (linha == "s") break;

        char comando = linha[0];
        std::istringstream iss(linha.substr(2));
        int pedido;

        if (comando == 'a') {
            iss >> pedido;
            pedidos.insert(pedido);
        } else if (comando == 'r') {
            iss >> pedido;
            if (pedidos.erase(pedido)) {
                std::cout << "removido\n";
            } else {
                std::cout << "falha\n";
            }
        } else if (comando == 'p') {
            if (pedidos.empty()) {
                std::cout << "vazia\n";
            } else {
                for (auto it = pedidos.begin(); it != pedidos.end(); ++it) {
                    if (it != pedidos.begin()) std::cout << " ";
                    std::cout << *it;
                }
                std::cout << "\n";
            }
        }
    }
    return 0;
}
