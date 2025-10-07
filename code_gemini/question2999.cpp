/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double x, y;
    std::cin >> x >> y;
    double media = (x + y) / 2.0;
    std::cout << std::fixed << std::setprecision(2) << media << std::endl;
    return 0;
}
