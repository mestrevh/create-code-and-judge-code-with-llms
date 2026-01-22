/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

bool is_vowel(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    char c1, c2, c3;
    if (!(std::cin >> c1 >> c2 >> c3)) {
        return 1;
    }

    if (!isupper(c1) || !isupper(c2) || !isupper(c3)) {
        std::cout << "Etiquetas erradas!" << std::endl;
        return 0;
    }

    std::vector<char> chars = {c1, c2, c3};
    std::sort(chars.begin(), chars.end());

    int dist1 = chars[1] - chars[0];
    int dist2 = chars[2] - chars[1];

    if (dist1 != dist2) {
        std::cout << "Só umas letras ai..." << std::endl;
        return 0;
    }

    bool has_vowel = is_vowel(chars[0]) || is_vowel(chars[1]) || is_vowel(chars[2]);
    int dist = dist1;

    if (dist == 1) {
        if (has_vowel) {
            std::cout << "Sequência quase perfeita." << std::endl;
        } else {
            std::cout << "Sequência perfeita." << std::endl;
        }
    } else if (dist == 2) {
        if (has_vowel) {
            std::cout << "Bissequência quase perfeita." << std::endl;
        } else {
            std::cout << "Bissequência perfeita." << std::endl;
        }
    } else if (dist == 3) {
        if (has_vowel) {
            std::cout << "Trissequência quase perfeita." << std::endl;
        } else {
            std::cout << "Trissequência perfeita." << std::endl;
        }
    } else {
        std::cout << "Só umas letras ai..." << std::endl;
    }

    return 0;
}
