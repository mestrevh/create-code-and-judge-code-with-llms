/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::cin.ignore();

    std::map<std::string, int> dwarf_food;
    std::vector<std::string> dwarves_in_order;

    for (int i = 0; i < n; ++i) {
        std::string line;
        std::getline(std::cin, line);

        size_t colon_pos = line.find(':');
        std::string command = line.substr(0, colon_pos);
        std::string name = line.substr(colon_pos + 1);

        if (command == "ENTROU") {
            int food;
            std::cin >> food;
            std::cin.ignore();
            
            if (dwarf_food.count(name)) {
                std::cout << "Anao ja estava em casa." << std::endl;
            } else {
                dwarf_food[name] = food;
                dwarves_in_order.push_back(name);
                std::cout << name << " entrou e gostaria de " << food << "g de comida." << std::endl;
            }
        } else if (command == "SAIU") {
            if (dwarf_food.count(name)) {
                dwarf_food.erase(name);
                dwarves_in_order.erase(std::remove(dwarves_in_order.begin(), dwarves_in_order.end(), name), dwarves_in_order.end());
                std::cout << name << " saiu de casa." << std::endl;
            } else {
                std::cout << name << " nao estava na casa." << std::endl;
            }
        }
    }

    std::cout << std::endl;

    if (dwarves_in_order.size() == 7) {
        std::cout << "teoria da branca de neve: porque só ter um se eu posso ter sete." << std::endl;
    } else {
        std::cout << "Estao na casa " << dwarves_in_order.size() << " anoes:" << std::endl;
    }

    long long total_food = 0;
    for (const std::string& name : dwarves_in_order) {
        std::cout << name << std::endl;
        total_food += dwarf_food[name];
    }
    
    if (!dwarves_in_order.empty() || total_food > 0) {
        std::cout << total_food << std::endl;
    } else if (dwarves_in_order.empty()) {
         std::cout << 0 << std::endl;
    }


    return 0;
}
