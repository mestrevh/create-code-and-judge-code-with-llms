/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    if (std::getline(std::cin, line)) {
        std::string decoded_line;
        decoded_line.reserve(line.length());

        for (char c : line) {
            switch (c) {
                case '0':
                    decoded_line += 'o';
                    break;
                case '1':
                    decoded_line += 'i';
                    break;
                case '2':
                    decoded_line += 'u';
                    break;
                case '4':
                    decoded_line += 'a';
                    break;
                case '5':
                    decoded_line += 'e';
                    break;
                default:
                    decoded_line += c;
                    break;
            }
        }

        bool capitalize_next = true;
        for (char &c : decoded_line) {
            if (capitalize_next && std::isalpha(static_cast<unsigned char>(c))) {
                c = std::toupper(static_cast<unsigned char>(c));
                capitalize_next = false;
            } else if (c == '.') {
                capitalize_next = true;
            }
        }
        
        std::cout << decoded_line << '\n';
    }

    return 0;
}
