/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double R, H;
    std::cin >> R >> H;
    double pi = 3.14159;
    double volume = pi * R * R * H;
    std::cout << std::fixed << std::setprecision(2) << volume << std::endl;
    return 0;
}
