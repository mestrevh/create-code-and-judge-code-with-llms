/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string input;
    std::cin >> input;

    std::string vowels;
    for (char c : input) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowels.push_back(c);
        }
    }

    std::string reversed_vowels = vowels;
    std::reverse(reversed_vowels.begin(), reversed_vowels.end());

    if (vowels == reversed_vowels) {
        std::cout << "S\n";
    } else {
        std::cout << "N\n";
    }

    return 0;
}
