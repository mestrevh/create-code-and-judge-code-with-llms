/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    char c;
    while (std::cin.get(c) && c != '\n') {
        if (c == '.' || c == '-') {
            std::cout << '\n';
        } else {
            std::cout << c;
        }
    }
    std::cout << '\n';
    return 0;
}
