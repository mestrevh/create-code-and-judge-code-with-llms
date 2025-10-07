/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::cin.ignore();

    for (int i = 1; i <= n; ++i) {
        std::string line;
        std::getline(std::cin, line);

        std::string clean_str;
        for (char c : line) {
            bool is_alphanumeric = (c >= 'a' && c <= 'z') ||
                                   (c >= 'A' && c <= 'Z') ||
                                   (c >= '0' && c <= '9');
            if (is_alphanumeric) {
                char lower_c = c;
                if (c >= 'A' && c <= 'Z') {
                    lower_c = c - 'A' + 'a';
                }
                clean_str += lower_c;
            }
        }

        bool is_palindrome = true;
        int len = clean_str.length();
        if (len > 0) {
            for (int j = 0; j < len / 2; ++j) {
                if (clean_str[j] != clean_str[len - 1 - j]) {
                    is_palindrome = false;
                    break;
                }
            }
        }

        std::cout << "Aluno " << i << ": ";
        if (is_palindrome) {
            std::cout << "Correto!, entendeu e trouxe um palindromo\n";
        } else {
            std::cout << "Incorreto!, não entendeu o que é um palindromo\n";
        }
    }

    return 0;
}
