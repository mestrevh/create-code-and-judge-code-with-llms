/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::stack<std::string>> machine(10);
    
    for (int i = 0; i < 10; ++i) {
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::string product;
        while (ss >> product) {
            machine[i].push(product);
        }
    }

    std::vector<double> prices(10);
    for (int i = 0; i < 10; ++i) {
        std::cin >> prices[i];
    }

    double total_cost = 0.0;
    std::string product_to_buy;
    
    while (std::cin >> product_to_buy) {
        bool found = false;
        for (int i = 0; i < 10; ++i) {
            if (!machine[i].empty() && machine[i].top() == product_to_buy) {
                found = true;
                int slot_number = 30 + i;
                
                if (slot_number == 35) {
                    std::cout << "Opa, um item 0800!\n";
                } else {
                    total_cost += prices[i];
                }
                machine[i].pop();
                break;
            }
        }
        if (!found) {
            std::cout << "Nao temos " << product_to_buy << " disponivel no momento.\n";
        }
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Compras realizadas com sucesso. Voce gastou R$" << total_cost << ".\n";

    return 0;
}
