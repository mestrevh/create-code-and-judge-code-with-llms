/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (std::cin >> n) {
        if (n == 1) {
            std::cout << "Bulbassauro\n";
        } else if (n == 2) {
            std::cout << "Charmander\n";
        } else if (n == 3) {
            std::cout << "Squirtle\n";
        }
    }

    return 0;
}