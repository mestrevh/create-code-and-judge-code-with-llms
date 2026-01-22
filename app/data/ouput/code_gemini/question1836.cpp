/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    while (std::getline(std::cin, line)) {
        if (line == "FIM") {
            break;
        }

        std::string converted_str;
        bool error = false;

        if (line.empty()) {
            error = true;
        } else {
            for (char c : line) {
                if (std::isdigit(c)) {
                    converted_str += c;
                } else if (c == 'o' || c == 'O') {
                    converted_str += '0';
                } else if (c == 'l') {
                    converted_str += '1';
                } else {
                    error = true;
                    break;
                }
            }
        }
        
        if (error) {
            std::cout << "ERRO\n";
        } else {
            size_t first_digit_pos = converted_str.find_first_not_of('0');
            if (std::string::npos == first_digit_pos) {
                std::cout << "0\n";
            } else {
                std::cout << converted_str.substr(first_digit_pos) << "\n";
            }
        }
    }

    return 0;
}
