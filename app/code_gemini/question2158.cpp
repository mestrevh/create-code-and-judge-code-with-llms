/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <clocale>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    setlocale(LC_ALL, "pt_BR.UTF-8");

    std::string line;
    std::getline(std::cin, line);

    std::map<std::string, int> word_counts;
    std::vector<std::string> repeated_words_in_order;
    std::string current_word;

    line += ' ';

    for (const unsigned char c : line) {
        if (isalpha(c)) {
            current_word += tolower(c);
        } else {
            if (!current_word.empty()) {
                word_counts[current_word]++;
                if (word_counts[current_word] == 2) {
                    repeated_words_in_order.push_back(current_word);
                }
                current_word.clear();
            }
        }
    }

    bool first_word = true;
    for (const std::string& word : repeated_words_in_order) {
        if (!first_word) {
            std::cout << " ";
        }
        std::cout << word;
        first_word = false;
    }
    std::cout << std::endl;

    return 0;
}
