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
    if (n == 1) {
        std::cout << "Bulbassauro\n";
    } else if (n == 2) {
        std::cout << "Charmander\n";
    } else if (n == 3) {
        std::cout << "Squirtle\n";
    }
    return 0;
}
