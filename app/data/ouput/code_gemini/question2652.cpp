/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    char limit_char;
    while (std::cin >> limit_char && limit_char != 'F') {
        for (char current_char = 'A'; current_char <= limit_char; ++current_char) {
            if (current_char > 'A') {
                std::cout << " ";
            }
            std::cout << current_char;
        }
        std::cout << '\n';
    }
    return 0;
}
