/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double x;
    std::cin >> x;

    std::cout << std::fixed << std::setprecision(6);
    std::cout << floor(x) << std::endl;
    std::cout << ceil(x) << std::endl;
    std::cout << sqrt(x) << std::endl;
    std::cout << sin(x) << std::endl;
    std::cout << cos(x) << std::endl;
    std::cout << pow(x, 6) << std::endl;

    return 0;
}
