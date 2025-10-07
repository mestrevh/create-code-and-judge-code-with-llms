/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double nota;
    std::cin >> nota;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Nota digitada: " << nota << std::endl;
    if (nota < 0.0 || nota > 10.0) {
        std::cout << "A nota nao esta no intervalo [0,10]" << std::endl;
    }
    return 0;
}
