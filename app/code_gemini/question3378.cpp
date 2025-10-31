/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double x;
    std::cin >> x;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "numero=" << x << std::endl;
    std::cout << "piso=" << floor(x) << std::endl;
    std::cout << "teto=" << ceil(x) << std::endl;
    std::cout << "raiz=" << sqrt(x) << std::endl;
    std::cout << "seno=" << sin(x) << std::endl;
    std::cout << "cosseno=" << cos(x) << std::endl;
    std::cout << "pot3=" << pow(x, 3) << std::endl;
    return 0;
}
