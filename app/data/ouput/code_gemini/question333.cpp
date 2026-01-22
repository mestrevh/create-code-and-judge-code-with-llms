/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::cin.ignore();

    bool capitalize_next = true;

    for (int i = 0; i < n; ++i) {
        std::string line;
        std::getline(std::cin, line);

        for (char &c : line) {
            if (capitalize_next && std::islower(c)) {
                c = std::toupper(c);
                capitalize_next = false;
            } else if (capitalize_next && std::isalpha(c)) {
                capitalize_next = false;
            }

            if (c == '.') {
                capitalize_next = true;
            }
        }
        std::cout << line << '\n';
    }

    return 0;
}
