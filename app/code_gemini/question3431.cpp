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

    std::vector<std::string> pedidos;
    std::string comando;

    while (std::cin >> comando) {
        if (comando == "ajuda") {
            std::cout << "-----------------------------------\n";
            std::cout << "Pizzaria 0.1 - menu de comandos\n";
            std::cout << "-----------------------------------\n";
            std::cout << "- ajuda: exibe o menu de ajuda\n";
            std::cout << "- sair: encerra o programa\n";
            std::cout << "- exibir: exibe a lista de pedidos\n";
            std::cout << "- novo #pedido: adiciona o #pedido\n";
            std::cout << "- cancela #pedido: remove o #pedido\n";
            std::cout << "-----------------------------------\n";
        } else if (comando == "sair") {
            break;
        } else if (comando == "exibir") {
            if (pedidos.empty()) {
                std::cout << "sem pedidos\n";
            } else {
                bool first = true;
                for (const auto& pedido : pedidos) {
                    if (!first) {
                        std::cout << " ";
                    }
                    std::cout << pedido;
                    first = false;
                }
                std::cout << "\n";
            }
        } else if (comando == "novo") {
            std::string numero_pedido;
            std::cin >> numero_pedido;
            pedidos.push_back(numero_pedido);
            std::cout << "pedido " << numero_pedido << " adicionado\n";
        } else if (comando == "cancela") {
            std::string numero_pedido;
            std::cin >> numero_pedido;
            auto it = std::find(pedidos.begin(), pedidos.end(), numero_pedido);
            if (it != pedidos.end()) {
                pedidos.erase(it);
                std::cout << "pedido " << numero_pedido << " removido\n";
            } else {
                std::cout << "pedido " << numero_pedido << " inexistente\n";
            }
        }
    }

    return 0;
}
