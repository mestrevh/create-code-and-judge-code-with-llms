/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int p1, c1, p2, c2;
    std::cin >> p1 >> c1 >> p2 >> c2;

    if (p1 < 10 || p1 > 100 || c1 < 10 || c1 > 100 || p2 < 10 || p2 > 100 || c2 < 10 || c2 > 100) {
        std::cout << "Restricao violada\n";
    } else {
        int lado_esquerdo = p1 * c1;
        int lado_direito = p2 * c2;

        if (lado_esquerdo == lado_direito) {
            std::cout << "Gangorra equilibrada\n";
        } else if (lado_esquerdo > lado_direito) {
            std::cout << "Gangorra desequilibrada para a esquerda\n";
        } else {
            std::cout << "Gangorra desequilibrada para a direita\n";
        }
    }

    return 0;
}
