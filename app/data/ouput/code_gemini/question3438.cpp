/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::cin.ignore(); 

    std::unordered_map<std::string, std::unordered_set<std::string>> supermarket;

    for (int i = 0; i < n; ++i) {
        std::string section_name;
        std::getline(std::cin, section_name);

        std::string items_line;
        std::getline(std::cin, items_line);

        std::stringstream ss(items_line);
        std::string item;
        while (ss >> item) {
            supermarket[section_name].insert(item);
        }
    }

    std::string query_line;
    while (std::getline(std::cin, query_line) && query_line != "FIM") {
        size_t comma_pos = query_line.find(',');
        
        std::string section = query_line.substr(0, comma_pos);
        std::string item = query_line.substr(comma_pos + 1);

        if (supermarket.count(section) && supermarket.at(section).count(item)) {
            std::cout << "Tem\n";
        } else {
            std::cout << "Indisponivel\n";
        }
    }

    return 0;
}
