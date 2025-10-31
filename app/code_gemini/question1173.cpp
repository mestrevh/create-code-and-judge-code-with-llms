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
    switch (n) {
        case 1:
            std::cout << "Bulbassauro\n";
            break;
        case 2:
            std::cout << "Charmander\n";
            break;
        case 3:
            std::cout << "Squirtle\n";
            break;
    }
    return 0;
}
