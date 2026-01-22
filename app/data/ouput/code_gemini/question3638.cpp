/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string text;
    std::string to_replace;
    std::string replacement;

    std::getline(std::cin, text);
    std::getline(std::cin, to_replace);
    std::getline(std::cin, replacement);

    size_t pos = text.find(to_replace);
    while (pos != std::string::npos) {
        text.replace(pos, to_replace.length(), replacement);
        pos = text.find(to_replace, pos + replacement.length());
    }

    std::cout << text << std::endl;

    return 0;
}
