/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double a;
    int negativos = 0;

    for (int i = 0; i < 5; ++i) {
        std::cout << "Digite um valor:" << std::endl;
        std::cin >> a;
        if (a < 0) {
            negativos++;
        }
    }

    std::cout << "Foram digitados " << negativos << " numeros negativos" << std::endl;

    return 0;
}
