/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string input;
    std::string phrase;
    int letter_count = 0;
    int word_count = 0;
    bool is_new_word = true;

    while (std::cin >> input && input != "fim") {
        if (input == "-") {
            is_new_word = true;
        } else {
            letter_count++;
            if (is_new_word) {
                word_count++;
                if (!phrase.empty()) {
                    phrase += " ";
                }
            }
            phrase += input;
            is_new_word = false;
        }
    }

    std::cout << "A palavra é: " << phrase << "\n";
    std::cout << "Ela tem " << word_count << " palavras\n";
    std::cout << "Ela tem " << letter_count << " letras\n";

    return 0;
}
