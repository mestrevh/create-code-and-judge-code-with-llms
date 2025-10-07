/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string word1, word2;
    std::cin >> word1 >> word2;

    if (word1.length() != word2.length()) {
        std::cout << "ERRO\n";
        return 0;
    }

    for (size_t i = 0; i < word1.length(); ++i) {
        if (std::isupper(static_cast<unsigned char>(word1[i])) || std::isupper(static_cast<unsigned char>(word2[i]))) {
            std::cout << "ERRO\n";
            return 0;
        }
    }

    std::string result = "";
    for (size_t i = 0; i < word1.length(); ++i) {
        char char1 = word1[i];
        char char2 = word2[i];
        
        bool is_vowel = (char1 == 'a' || char1 == 'e' || char1 == 'i' || char1 == 'o' || char1 == 'u');

        if (char1 == char2 && !is_vowel) {
            result += std::to_string(i);
        } else if (i % 2 == 0) {
            result += std::toupper(static_cast<unsigned char>(char1));
        } else {
            result += "!!";
        }
    }

    std::cout << result << "\n";

    return 0;
}
