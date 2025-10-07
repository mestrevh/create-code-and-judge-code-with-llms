/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<std::string> evens;
    std::vector<std::string> odds;
    for (int i = 0; i < n; ++i) {
        std::string name;
        int g;
        std::cin >> name >> g;
        if (g % 2 == 0) {
            evens.push_back(name);
        } else {
            odds.push_back(name);
        }
    }
    for (const auto& name : evens) {
        std::cout << name << '\n';
    }
    for (const auto& name : odds) {
        std::cout << name << '\n';
    }
    return 0;
}
