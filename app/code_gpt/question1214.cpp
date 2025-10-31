/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

std::string transform(const std::string& line) {
    std::string result;
    int symbol_count = 0;

    for (char c : line) {
        if (std::isspace(c)) continue;
        
        if (std::isdigit(c)) {
            switch (c) {
                case '0': result += '*'; break;
                case '1': result += ')'; break;
                case '2': result += '$'; break;
                case '3': result += '!'; break;
                case '4': result += '+'; break;
                case '5': result += '@'; break;
                case '6': result += '-'; break;
                case '7': result += '/'; break;
                case '8': result += '('; break;
                case '9': result += '%'; break;
            }
        } else if (std::isupper(c)) {
            result += std::to_string(c - 'A' + 1);
        } else if (std::islower(c)) {
            result += (symbol_count % 2 == 0) ? std::toupper(c) : std::tolower(c);
        }

        if (!std::isdigit(c) && !std::isspace(c)) symbol_count++;
    }

    return result;
}

int main() {
    std::string line;
    std::string output;

    while (std::getline(std::cin, line)) {
        output = transform(line) + "\n" + output;
    }

    std::cout << output;
    return 0;
}
