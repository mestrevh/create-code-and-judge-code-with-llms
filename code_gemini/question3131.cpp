/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <set>
#include <sstream>
#include <cctype>
#include <algorithm>

std::string remover_especiais(std::string palavra) {
    std::string resultado;
    for (char c : palavra) {
        if (std::isalpha(static_cast<unsigned char>(c))) {
            resultado += std::tolower(static_cast<unsigned char>(c));
        }
    }
    return resultado;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::set<std::string> dictionary;
    std::string line;
    bool stop_processing = false;

    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        std::string token;
        while (ss >> token) {
            if (token == "-1") {
                stop_processing = true;
                break;
            }
            std::string word = remover_especiais(token);
            if (!word.empty()) {
                dictionary.insert(word);
            }
        }
        if (stop_processing) {
            break;
        }
    }

    for (const auto& word : dictionary) {
        std::cout << word << std::endl;
    }

    return 0;
}
