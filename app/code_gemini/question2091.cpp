/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::map<std::string, int> dwarf_food;
    std::vector<std::string> present_dwarves;

    for (int i = 0; i < n; ++i) {
        std::string op;
        std::string name;
        std::getline(std::cin, op, ':');
        std::getline(std::cin, name);

        if (op == "ENTROU") {
            int q;
            std::cin >> q;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (dwarf_food.count(name)) {
                std::cout << "Anao ja estava em casa.\n";
            } else {
                dwarf_food[name] = q;
                present_dwarves.push_back(name);
                std::cout << name << " entrou e gostaria de " << q << "g de comida.\n";
            }
        } else if (op == "SAIU") {
            if (dwarf_food.count(name)) {
                dwarf_food.erase(name);
                auto it = std::find(present_dwarves.begin(), present_dwarves.end(), name);
                if (it != present_dwarves.end()) {
                    present_dwarves.erase(it);
                }
                std::cout << name << " saiu de casa.\n";
            } else {
                std::cout << name << " nao estava na casa.\n";
            }
        }
    }

    std::cout << "\n";

    int count = present_dwarves.size();
    if (count == 7) {
        std::cout << "teoria da branca de neve: porque so ter um se eu posso ter sete?\n";
    } else {
        std::cout << "Estao na casa " << count << " anoes:\n";
    }

    for (const auto& dwarf_name : present_dwarves) {
        std::cout << dwarf_name << "\n";
    }
    
    long long total_food = 0;
    for(const auto& pair : dwarf_food) {
        total_food += pair.second;
    }
    std::cout << total_food << "\n";

    return 0;
}
