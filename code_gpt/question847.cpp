/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string text;
    std::getline(std::cin, text);
    int word_count = 0;
    bool in_word = false;

    for (char c : text) {
        if (isalpha(c)) {
            if (!in_word) {
                in_word = true;
                word_count++;
            }
        } else {
            in_word = false;
        }
    }

    std::cout << word_count << std::endl;
    return 0;
}
