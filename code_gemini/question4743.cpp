/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int c;
    std::cin >> c;
    double f = (9.0 * c) / 5.0 + 32.0;
    std::cout << std::fixed << std::setprecision(1) << f << std::endl;
    return 0;
}

