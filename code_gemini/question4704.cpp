/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

std::string inverter_string(const std::string& s) {
    return std::string(s.rbegin(), s.rend());
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string linha;
    std::getline(std::cin, linha);

    std::cout << inverter_string(linha) << std::endl;

    return 0;
}
