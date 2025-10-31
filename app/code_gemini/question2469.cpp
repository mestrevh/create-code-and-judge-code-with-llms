/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

void print_friend_section(const std::string& name, const std::vector<std::string>& items) {
    if (items.empty()) {
        std::cout << name << " não pediu nada.\n";
    } else {
        std::cout << name << ":\n";
        for (const std::string& item : items) {
            std::cout << "-" << item << "\n";
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int I;
    std::cin >> I;

    std::vector<std::string> chandler_pedidos;
    std::vector<std::string> phoebe_pedidos;
    std::vector<std::string> joey_pedidos;
    std::vector<std::string> monica_pedidos;
    std::vector<std::string> ross_pedidos;
    std::vector<std::string> outros_pedidos;

    for (int i = 0; i < I; ++i) {
        std::string comida, tipo;
        std::cin >> comida >> tipo;

        if (tipo == "Cafe") {
            chandler_pedidos.push_back(comida);
        } else if (tipo == "Cha") {
            phoebe_pedidos.push_back(comida);
        } else if (tipo == "Cerveja") {
            joey_pedidos.push_back(comida);
        } else if (tipo == "Refrigerante") {
            monica_pedidos.push_back(comida);
        } else if (tipo == "Suco") {
            ross_pedidos.push_back(comida);
        } else {
            outros_pedidos.push_back(comida);
        }
    }

    bool friends_ordered = !chandler_pedidos.empty() || !phoebe_pedidos.empty() ||
                           !joey_pedidos.empty() || !monica_pedidos.empty() ||
                           !ross_pedidos.empty();

    if (!friends_ordered) {
        std::cout << "Nenhum dos meus amigos veio, não vou trabalhar hoje.\n";
    } else {
        print_friend_section("Chandler", chandler_pedidos);
        std::cout << "\n";
        print_friend_section("Phoebe", phoebe_pedidos);
        std::cout << "\n";
        print_friend_section("Joey", joey_pedidos);
        std::cout << "\n";
        print_friend_section("Monica", monica_pedidos);
        std::cout << "\n";
        print_friend_section("Ross", ross_pedidos);

        if (!outros_pedidos.empty()) {
            std::cout << "\n";
            std::cout << "Outros Clientes:\n";
            for (const std::string& item : outros_pedidos) {
                std::cout << "-" << item << "\n";
            }
        }
    }

    return 0;
}
