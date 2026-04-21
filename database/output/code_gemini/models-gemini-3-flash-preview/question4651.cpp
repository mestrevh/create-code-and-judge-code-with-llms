/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            std::cout << "\n";
            continue;
        }

        bool next_is_capital = true;
        for (int i = 0; i < (int)line.length(); ++i) {
            unsigned char c = static_cast<unsigned char>(line[i]);
            if (std::isspace(c)) {
                next_is_capital = true;
                std::cout << (char)c;
            } else {
                if (next_is_capital) {
                    std::cout << (char)std::toupper(c);
                    next_is_capital = false;
                } else {
                    std::cout << (char)std::tolower(c);
                }
            }
        }
        std::cout << "\n";
    }

    return 0;
}