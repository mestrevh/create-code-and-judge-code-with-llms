/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

void maior_numero(double a, double b) {
    if (a > b) {
        std::cout << std::fixed << std::setprecision(1) << a << std::endl;
    } else if (b > a) {
        std::cout << std::fixed << std::setprecision(1) << b << std::endl;
    } else {
        std::cout << "São iguais" << std::endl;
    }
}

int main() {
    double num1, num2;
    std::cin >> num1 >> num2;
    maior_numero(num1, num2);
    return 0;
}
