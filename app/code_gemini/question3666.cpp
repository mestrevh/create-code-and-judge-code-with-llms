/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void print_list(const std::vector<std::string>& list) {
    for (const auto& name : list) {
        std::cout << name << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::string> guests;
    std::string name;

    while (std::getline(std::cin, name) && name != "FIM") {
        guests.push_back(name);
    }

    std::sort(guests.begin(), guests.end());

    print_list(guests);

    int n;
    while (std::cin >> n && n != 0) {
        std::cout << std::string(50, '-') << '\n';
        
        std::cin.ignore(); 

        for (int i = 0; i < n; ++i) {
            std::getline(std::cin, name);
            auto it = std::lower_bound(guests.begin(), guests.end(), name);
            guests.insert(it, name);
        }

        print_list(guests);
    }

    return 0;
}
