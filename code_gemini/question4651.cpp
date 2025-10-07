/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>
#include <clocale>

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    if (std::getline(std::cin, line)) {
        bool capitalize = true;
        for (char &c : line) {
            if (std::isspace(static_cast<unsigned char>(c))) {
                capitalize = true;
            } else if (capitalize) {
                c = std::toupper(static_cast<unsigned char>(c));
                capitalize = false;
            } else {
                c = std::tolower(static_cast<unsigned char>(c));
            }
        }
        std::cout << line << std::endl;
    }

    return 0;
}
