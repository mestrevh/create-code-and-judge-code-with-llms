/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cctype>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    char x;
    std::cin >> x;

    if (isalpha(x)) {
        char lower_x = tolower(x);
        if (lower_x == 'a' || lower_x == 'e' || lower_x == 'i' || lower_x == 'o' || lower_x == 'u') {
            std::cout << "A letra " << x << " eh uma vogal" << std::endl;
        } else {
            std::cout << "A letra " << x << " eh uma consoante" << std::endl;
        }
    } else {
        std::cout << "O caractere " << x << " nao eh nem consoante nem vogal" << std::endl;
    }

    return 0;
}
