/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    if (s.find("zelda") != std::string::npos) {
        std::cout << "Link Bolado" << std::endl;
    } else {
        std::cout << "Link Tranquilo" << std::endl;
    }
    return 0;
}
