/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <unordered_set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    std::unordered_set<std::string> exceptions = {"da", "de", "di", "do", "du", "e"};

    while (std::getline(std::cin, line)) {
        if (line == "*") {
            break;
        }

        std::istringstream iss(line);
        std::string word;
        bool first_word_printed = false;

        while (iss >> word) {
            if (first_word_printed) {
                std::cout << " ";
            }

            for (char &c : word) {
                c = std::tolower(c);
            }

            if (exceptions.find(word) == exceptions.end()) {
                if (!word.empty()) {
                    word[0] = std::toupper(word[0]);
                }
            }

            std::cout << word;
            first_word_printed = true;
        }
        std::cout << std::endl;
    }

    return 0;
}
