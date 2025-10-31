/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string s;
    std::getline(std::cin, s);
    std::string reversed_s = s;
    std::reverse(reversed_s.begin(), reversed_s.end());
    if (s == reversed_s) {
        std::cout << "SIM" << std::endl;
        std::cout << s.length() / 2 << std::endl;
    } else {
        std::cout << "NAO" << std::endl;
    }
    return 0;
}
