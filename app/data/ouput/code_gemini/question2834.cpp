/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::string> yes_candidates;
    std::set<std::string> unique_yes_names;
    std::vector<std::string> no_names;
    std::string name, choice;

    while (std::cin >> name && name != "FIM") {
        std::cin >> choice;
        if (choice == "YES") {
            if (unique_yes_names.find(name) == unique_yes_names.end()) {
                unique_yes_names.insert(name);
                yes_candidates.push_back(name);
            }
        } else {
            no_names.push_back(name);
        }
    }

    std::string winner = "";
    if (!yes_candidates.empty()) {
        winner = yes_candidates[0];
        for (size_t i = 1; i < yes_candidates.size(); ++i) {
            if (yes_candidates[i].length() > winner.length()) {
                winner = yes_candidates[i];
            }
        }
    }

    std::sort(no_names.begin(), no_names.end());

    for (const auto& yes_name : unique_yes_names) {
        std::cout << yes_name << '\n';
    }
    for (const auto& no_name : no_names) {
        std::cout << no_name << '\n';
    }

    std::cout << '\n';
    std::cout << "Amigo do Habay:\n";
    std::cout << winner << '\n';

    return 0;
}
