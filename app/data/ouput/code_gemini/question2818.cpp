/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double ph;

    std::cout << "Digite o pH da solucao:" << std::endl;
    std::cin >> ph;

    if (ph < 0.0 || ph > 14.0) {
        std::cout << "Valor do pH deve estar entre 0 e 14" << std::endl;
    } else if (ph < 7.0) {
        std::cout << "Solucao acida" << std::endl;
    } else if (ph > 7.0) {
        std::cout << "Solucao basica" << std::endl;
    } else {
        std::cout << "Solucao neutra" << std::endl;
    }

    return 0;
}
