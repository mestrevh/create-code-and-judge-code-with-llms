/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>
#include <iomanip>
#include <sstream>
#include <string>

int main() {
    std::map<std::string, double> compras;
    std::string linha, comando;

    while (std::getline(std::cin, linha) && linha != "*") {
        std::istringstream iss(linha);
        std::string produto;
        double preco;
        std::getline(iss, produto, ' ');
        iss >> preco;
        compras[produto] += preco; // Adiciona preço ao produto
    }

    while (std::getline(std::cin, comando)) {
        if (comando == "total") {
            double total = 0;
            for (const auto& item : compras)
                total += item.second;
            std::cout << std::fixed << std::setprecision(2) << total << std::endl;
            break;
        } else if (comando == "quantidade") {
            std::cout << compras.size() << std::endl;
        } else if (comando.substr(0, 6) == "retire ") {
            std::string produto = comando.substr(7);
            compras.erase(produto); // Retira o produto
        }
    }

    return 0;
}
