/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string line;
    std::getline(std::cin, line);
    
    int word_count = 0;
    bool in_word = false;
    
    for (char c : line) {
        if (std::isalpha(c)) {
            if (!in_word) {
                word_count++;
                in_word = true;
            }
        } else {
            in_word = false;
        }
    }
    
    std::cout << word_count << std::endl;
    
    return 0;
}
