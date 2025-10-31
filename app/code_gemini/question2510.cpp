/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

struct Present {
    std::string name;
    double price;
    int preference;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string personName;
    int Q;
    bool first_case = true;

    while (std::cin >> personName && personName != "*") {
        if (!first_case) {
            std::cout << std::endl;
        }

        std::cin >> Q;
        std::cin.ignore(); 

        std::vector<Present> presents;
        for (int i = 0; i < Q; ++i) {
            Present current_present;
            std::getline(std::cin, current_present.name);
            std::cin >> current_present.price >> current_present.preference;
            std::cin.ignore(); 
            presents.push_back(current_present);
        }

        std::sort(presents.begin(), presents.end(), [](const Present& a, const Present& b) {
            if (a.preference != b.preference) {
                return a.preference > b.preference;
            }
            if (a.price != b.price) {
                return a.price < b.price;
            }
            return a.name < b.name;
        });

        std::cout << "Lista de " << personName << std::endl;
        for (const auto& p : presents) {
            std::cout << p.name << " - R$" << std::fixed << std::setprecision(2) << p.price << std::endl;
        }

        first_case = false;
    }

    return 0;
}
