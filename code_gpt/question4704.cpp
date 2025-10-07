/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

std::string inverter_string(const std::string& str) {
    std::string inverted = str;
    std::reverse(inverted.begin(), inverted.end());
    return inverted;
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::cout << inverter_string(input) << std::endl;
    return 0;
}
