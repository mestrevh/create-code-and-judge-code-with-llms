/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int pessoas = 0;
    double peso_total = 0.0;
    double peso_pessoa;

    while (pessoas < 7) {
        std::cin >> peso_pessoa;
        if (peso_pessoa == 0) {
            break;
        }
        if (peso_total + peso_pessoa > 560) {
            break;
        }
        pessoas++;
        peso_total += peso_pessoa;
    }

    std::cout << pessoas << std::endl;
    std::cout << std::fixed << std::setprecision(1) << peso_total << std::endl;

    return 0;
}
