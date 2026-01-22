/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string s;
    std::getline(std::cin, s);
    const auto first = s.find_first_not_of(" ");
    if (std::string::npos == first) {
        std::cout << "" << std::endl;
        return 0;
    }
    const auto last = s.find_last_not_of(" ");
    std::cout << s.substr(first, (last - first + 1)) << std::endl;
    return 0;
}
