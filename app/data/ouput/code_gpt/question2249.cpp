/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

std::string processLine(const std::string& line) {
    std::string result;
    int symbolCount = 0;
    
    for (char ch : line) {
        if (std::isspace(ch) || std::ispunct(ch)) {
            // Ignore spaces and punctuation
            if (std::ispunct(ch)) symbolCount++;
            continue;
        }
        if (std::isdigit(ch)) {
            switch (ch) {
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
        } else if (std::isupper(ch)) {
            result += std::to_string(ch - 'A' + 1);
        } else if (std::islower(ch)) {
            result += (symbolCount % 2 == 0) ? std::toupper(ch) : ch;
        }
    }
    
    return result;
}

int main() {
    std::string line;
    std::vector<std::string> lines;

    while (std::getline(std::cin, line)) {
        lines.push_back(processLine(line));
    }
    
    std::reverse(lines.begin(), lines.end());
    
    for (const auto& processedLine : lines) {
        std::cout << processedLine << std::endl;
    }

    return 0;
}
