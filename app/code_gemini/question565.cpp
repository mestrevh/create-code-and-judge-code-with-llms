/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <string>

int main() {
    std::cout << "Digite um número com no máximo 5 algarismos: ";

    long long n;
    
    if (!(std::cin >> n)) {
        std::cout << "Entrada incorreta!" << std::endl;
        return 0;
    }

    long long abs_n = std::abs(n);

    if (abs_n > 99999) {
        std::cout << "Entrada incorreta!" << std::endl;
    } else if (abs_n >= 10000) {
        std::cout << "O número possui 5 algarismos!" << std::endl;
    } else if (abs_n >= 1000) {
        std::cout << "O número possui 4 algarismos!" << std::endl;
    } else if (abs_n >= 100) {
        std::cout << "O número possui 3 algarismos!" << std::endl;
    } else if (abs_n >= 10) {
        std::cout << "O número possui 2 algarismos!" << std::endl;
    } else {
        std::cout << "O número possui 1 algarismos!" << std::endl;
    }

    return 0;
}
