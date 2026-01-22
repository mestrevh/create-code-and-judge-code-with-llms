/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    double valor;
    std::cin >> valor;
    if (valor >= 0 && valor <= 25) {
        std::cout << "Intervalo [0,25]" << std::endl;
    } else if (valor > 25 && valor <= 50) {
        std::cout << "Intervalo (25,50]" << std::endl;
    } else if (valor > 50 && valor <= 75) {
        std::cout << "Intervalo (50,75]" << std::endl;
    } else if (valor > 75 && valor <= 100) {
        std::cout << "Intervalo (75,100]" << std::endl;
    } else {
        std::cout << "Fora de intervalo" << std::endl;
    }
    return 0;
}
