/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double metros;
    std::cin >> metros;

    std::cout << "Insira um valor em metros:" << std::endl;

    double centimetros = metros * 100.0;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Resultado: " << centimetros << std::endl;

    return 0;
}
