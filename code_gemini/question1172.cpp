/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int cp;
    std::cin >> cp;

    if (cp >= 1000 && cp <= 9999) {
        int ab = cp / 100;
        int cd = cp % 100;
        int sum = ab + cd;

        if (sum * sum == cp) {
            std::cout << "Charmander vitorioso\n";
        } else {
            std::cout << "Charmander derrotado\n";
        }
    } else {
        std::cout << "Charmander derrotado\n";
    }

    return 0;
}
