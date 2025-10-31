/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cctype>

int main() {
    int n;
    char c;
    std::cin >> n >> c;

    if (n >= 0 && n <= 99) {
        if (!isalnum(c)) {
            std::cout << "Caminhão 1" << std::endl;
        } else if (n % 2 == 0 && (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                                  c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')) {
            std::cout << "Caminhão 2" << std::endl;
        } else if (n % 2 != 0 && isupper(c)) {
            std::cout << "Caminhão 3" << std::endl;
        } else {
            std::cout << "Caminhão 4" << std::endl;
        }
    }

    return 0;
}
