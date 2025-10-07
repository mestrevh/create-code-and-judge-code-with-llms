/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::map<std::string, int> stock;
    std::vector<std::string> product_order;

    for (int i = 0; i < n; ++i) {
        std::string command;
        std::getline(std::cin, command);

        if (command == "CADASTRO") {
            std::string product;
            std::getline(std::cin, product);
            if (stock.count(product)) {
                std::cout << "Produto ja cadastrado\n";
            } else {
                stock[product] = 0;
                product_order.push_back(product);
                std::cout << "Produto cadastrado com sucesso\n";
            }
        } else if (command == "ESTOQUE" || command == "VENDA") {
            std::string product;
            std::getline(std::cin, product);
            int quantity;
            std::cin >> quantity;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            if (quantity < 0) {
                 std::cout << "Comando invalido\n";
            } else if (!stock.count(product)) {
                std::cout << "Produto nao foi cadastrado\n";
            } else {
                if (command == "ESTOQUE") {
                    stock[product] += quantity;
                    std::cout << "Estoque realizado com sucesso\n";
                } else { // VENDA
                    if (stock[product] < quantity) {
                        std::cout << "Nao ha estoque para a venda\n";
                    } else {
                        stock[product] -= quantity;
                        std::cout << "Venda realizada com sucesso\n";
                    }
                }
            }
        } else {
            std::cout << "Comando invalido\n";
        }
    }

    for (const std::string& product : product_order) {
        std::cout << product << ": " << stock[product] << "\n";
    }

    return 0;
}
