/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

bool inverter_string2(const std::string& s) {
    std::string cleaned;
    for (char c : s) {
        if (std::isalnum(c)) {
            cleaned += std::tolower(c);
        }
    }
    std::string reversed = cleaned;
    std::reverse(reversed.begin(), reversed.end());
    return cleaned == reversed;
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    if (inverter_string2(input)) {
        std::cout << "Eh um palindromo" << std::endl;
    } else {
        std::cout << "Nao eh um palindromo" << std::endl;
    }
    return 0;
}
