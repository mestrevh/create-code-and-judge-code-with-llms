/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    char c;
    std::cin >> n >> c;

    if (!isalpha(c)) {
        std::cout << "Caminhão 1\n";
    } else {
        char lower_c = tolower(c);
        bool is_vowel = (lower_c == 'a' || lower_c == 'e' || lower_c == 'i' || lower_c == 'o' || lower_c == 'u');

        if (n % 2 == 0 && is_vowel) {
            std::cout << "Caminhão 2\n";
        } else if (n % 2 != 0 && isupper(c)) {
            std::cout << "Caminhão 3\n";
        } else {
            std::cout << "Caminhão 4\n";
        }
    }

    return 0;
}
