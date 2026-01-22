/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string line;
    bool is_open = true;
    while (std::getline(std::cin, line)) {
        if (line == "_") {
            break;
        }
        for (char c : line) {
            if (c == '+') {
                if (is_open) {
                    std::cout << '*';
                } else {
                    std::cout << '#';
                }
                is_open = !is_open;
            } else {
                std::cout << c;
            }
        }
        std::cout << '\n';
    }
    return 0;
}
