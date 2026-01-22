/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>

std::string formatName(const std::string& name) {
    std::vector<std::string> exceptions = {"da", "de", "di", "do", "du", "e"};
    std::istringstream iss(name);
    std::string word;
    std::string result;
    
    while (iss >> word) {
        if (!result.empty()) result += ' ';
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        if (std::find(exceptions.begin(), exceptions.end(), word) == exceptions.end()) {
            word[0] = toupper(word[0]);
        }
        result += word;
    }
    
    return result;
}

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        if (line == "*") break;
        auto trimmed = line;
        trimmed.erase(trimmed.begin(), std::find_if(trimmed.begin(), trimmed.end(), [](unsigned char c) { return !std::isspace(c); }));
        trimmed.erase(std::find_if(trimmed.rbegin(), trimmed.rend(), [](unsigned char c) { return !std::isspace(c); }).base(), trimmed.end());
        std::cout << formatName(trimmed) << std::endl;
    }
    return 0;
}
