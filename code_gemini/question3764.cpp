/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double ph;
    while (std::cin >> ph && ph != -1.0) {
        if (ph < 7.0) {
            std::cout << "ACIDA\n";
        } else if (ph > 7.0) {
            std::cout << "BASICA\n";
        } else {
            std::cout << "NEUTRA\n";
        }
    }
    return 0;
}
