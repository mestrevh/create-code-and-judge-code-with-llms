/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string name;
    std::cin >> name;

    std::transform(name.begin(), name.end(), name.begin(),
                   [](unsigned char c){ return std::toupper(c); });

    for (size_t i = 1; i <= name.length(); ++i) {
        std::cout << name.substr(0, i) << '\n';
    }

    return 0;
}
