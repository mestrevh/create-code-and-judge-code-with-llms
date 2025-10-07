/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

bool is_consonant(char c) {
    return c >= 'A' && c <= 'Z' && !(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

bool is_uppercase(char c) {
    return c >= 'A' && c <= 'Z';
}

int main() {
    std::vector<char> chars(3);
    for (int i = 0; i < 3; i++) {
        std::cin >> chars[i];
        if (!is_uppercase(chars[i])) {
            std::cout << "Etiquetas erradas!" << std::endl;
            return 0;
        }
    }
    std::sort(chars.begin(), chars.end());
    std::set<char> unique_chars(chars.begin(), chars.end());
    
    if (unique_chars.size() < 3) {
        std::cout << "Só umas letras ai..." << std::endl;
        return 0;
    }

    int d1 = chars[1] - chars[0];
    int d2 = chars[2] - chars[1];

    bool contains_vowel = !is_consonant(chars[0]) || !is_consonant(chars[1]) || !is_consonant(chars[2]);
    
    if (d1 == 1 && d2 == 1) {
        std::cout << (contains_vowel ? "Sequência quase perfeita." : "Sequência perfeita.") << std::endl;
    } else if (d1 == 2 && d2 == 2) {
        std::cout << (contains_vowel ? "Bissequência quase perfeita." : "Bissequência perfeita.") << std::endl;
    } else if (d1 == 3 && d2 == 3) {
        std::cout << (contains_vowel ? "Trissequência quase perfeita." : "Trissequência perfeita.") << std::endl;
    } else {
        std::cout << "Só umas letras ai..." << std::endl;
    }

    return 0;
}
