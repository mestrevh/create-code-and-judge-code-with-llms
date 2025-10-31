/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::map<std::string, double> shopping_list;
    std::string line;

    while (std::getline(std::cin, line) && line != "*") {
        size_t last_space_pos = line.find_last_of(' ');
        if (last_space_pos != std::string::npos) {
            std::string name = line.substr(0, last_space_pos);
            double price = std::stod(line.substr(last_space_pos + 1));
            shopping_list[name] = price;
        }
    }

    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            continue;
        }

        std::stringstream ss(line);
        std::string command;
        ss >> command;

        if (command == "quantidade") {
            std::cout << shopping_list.size() << std::endl;
        } else if (command == "retire") {
            std::string product_to_remove;
            std::getline(ss, product_to_remove);
            if (!product_to_remove.empty() && product_to_remove[0] == ' ') {
                product_to_remove = product_to_remove.substr(1);
            }
            shopping_list.erase(product_to_remove);
        } else if (command == "total") {
            double total_cost = 0.0;
            for (const auto& pair : shopping_list) {
                total_cost += pair.second;
            }
            std::cout << std::fixed << std::setprecision(2) << total_cost << std::endl;
            break;
        }
    }

    return 0;
}
