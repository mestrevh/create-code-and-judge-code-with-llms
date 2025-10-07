/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

void inverter_string2(std::string str) {
    std::string cleaned_str;
    for (char c : str) {
        if (!isspace(c)) {
            cleaned_str += tolower(c);
        }
    }

    std::string reversed_str = cleaned_str;
    std::reverse(reversed_str.begin(), reversed_str.end());

    if (cleaned_str == reversed_str) {
        std::cout << "Eh um palindromo" << std::endl;
    } else {
        std::cout << "Nao eh um palindromo" << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string input_line;
    std::getline(std::cin, input_line);

    inverter_string2(input_line);

    return 0;
}
