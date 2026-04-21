/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    while (std::getline(std::cin, s)) {
        // Handle Windows-style line endings
        if (!s.empty() && s.back() == '\r') {
            s.pop_back();
        }

        // Constraints: 1 <= size <= 20
        if (s.length() < 1 || s.length() > 20) {
            std::cout << "Entrada invalida" << "\n";
        } else {
            int n = (int)s.length();
            for (int i = 0; i < n; ++i) {
                char upper_c = (char)std::toupper((unsigned char)s[i]);
                // Repeat the character (i + 1) times for the (i + 1)-th row
                for (int j = 0; j <= i; ++j) {
                    std::cout << upper_c;
                }
                std::cout << "\n";
            }
            // Exit the loop once a valid input is processed
            break;
        }
    }

    return 0;
}