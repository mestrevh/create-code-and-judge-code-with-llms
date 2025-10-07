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
    std::cin >> s;
    char c;
    std::cin >> c;
    size_t pos = s.find(c);
    if (pos == std::string::npos) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << pos << std::endl;
    }
    return 0;
}
