/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <set>
#include <string>
#include <algorithm>

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::set<char> unique_chars;

    for (char c : input) {
        if (std::isalpha(c)) {
            unique_chars.insert(tolower(c));
        }
    }

    for (char c : unique_chars) {
        std::cout << c << std::endl;
    }

    return 0;
}
