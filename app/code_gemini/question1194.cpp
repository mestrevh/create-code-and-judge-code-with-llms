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

    while (std::getline(std::cin, line)) {
        for (char &c : line) {
            if (c >= 'a' && c <= 'z') {
                c = 'a' + (c - 'a' + 6) % 26;
            } else if (c >= 'A' && c <= 'Z') {
                c = 'A' + (c - 'A' + 6) % 26;
            }
        }
        std::cout << line << '\n';
    }

    return 0;
}
