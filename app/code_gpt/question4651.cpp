/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>
#include <cctype>

std::string formatName(const std::string& name) {
    std::string result;
    std::istringstream iss(name);
    std::string word;

    while (iss >> word) {
        if (!word.empty()) {
            word[0] = std::toupper(word[0]);
            for (std::size_t i = 1; i < word.length(); ++i) {
                word[i] = std::tolower(word[i]);
            }
            result += word + ' ';
        }
    }

    if (!result.empty()) {
        result.pop_back();
    }
    
    return result;
}

int main() {
    std::string name;
    std::getline(std::cin, name);
    std::cout << formatName(name) << std::endl;
    return 0;
}
