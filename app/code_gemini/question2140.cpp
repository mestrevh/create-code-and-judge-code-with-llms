/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string verbo;
    std::cin >> verbo;
    std::string base = verbo.substr(0, verbo.length() - 1);
    std::cout << base << " " << base << "ndo" << std::endl;
    return 0;
}
