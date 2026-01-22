/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

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
