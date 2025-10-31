/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    double ph;
    std::cout << "Digite o pH da solucao:" << std::endl;
    std::cin >> ph;
    if (ph < 0 || ph > 14) {
        std::cout << "Valor deve estar entre 0 e 14." << std::endl;
    } else if (ph < 7) {
        std::cout << "Essa solucao e acida." << std::endl;
    } else if (ph > 7) {
        std::cout << "Essa solucao e basica." << std::endl;
    } else {
        std::cout << "Essa solucao e neutra." << std::endl;
    }
    return 0;
}
