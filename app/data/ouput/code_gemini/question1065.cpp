/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    if (n % 5 == 0) {
        std::cout << "Eh multiplo de 5\n";
    } else {
        std::cout << "Nao eh multiplo de 5\n";
    }
    return 0;
}
