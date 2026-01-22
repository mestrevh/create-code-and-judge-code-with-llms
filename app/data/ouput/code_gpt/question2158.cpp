/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <map>
#include <cctype>
#include <algorithm>

std::string normalize(const std::string &word) {
    std::string normalized;
    for (char c : word) {
        if (std::isalpha(c, std::locale("pt_BR.UTF-8")) || c == 'á' || c == 'ã' || c == 'â' || c == 'ç' ||
            c == 'é' || c == 'ê' || c == 'í' || c == 'ó' || c == 'õ' || c == 'ô' || c == 'ú' || c == 'ü' ||
            c == 'Á' || c == 'Ã' || c == 'Â' || c == 'Ç' || c == 'É' || c == 'Ê' || c == 'Í' || c == 'Ó' ||
            c == 'Õ' || c == 'Ô' || c == 'Ú') {
            normalized += std::tolower(c, std::locale("pt_BR.UTF-8"));
        }
    }
    return normalized;
}

int main() {
    std::string text;
    std::getline(std::cin, text);
    std::istringstream iss(text);
    std::map<std::string, int> wordCount;
    std::set<std::string> repeatedWords;
    std::vector<std::string> order;

    std::string word;
    while (iss >> word) {
        std::string normalizedWord = normalize(word);
        if (!normalizedWord.empty()) {
            wordCount[normalizedWord]++;
            if (wordCount[normalizedWord] == 2) {
                repeatedWords.insert(normalizedWord);
                order.push_back(normalizedWord);
            }
        }
    }

    for (const auto &w : order) {
        if (repeatedWords.count(w)) {
            std::cout << w << " ";
        }
    }

    return 0;
}
