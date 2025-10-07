/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int contarCaracteres(const std::string &s) {
    if (s.empty()) return 0;
    return 1 + contarCaracteres(s.substr(1));
}

int main() {
    std::string entrada;
    std::getline(std::cin, entrada);
    std::cout << contarCaracteres(entrada) << std::endl;
    return 0;
}
