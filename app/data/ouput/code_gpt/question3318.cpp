/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double n;
    std::cin >> n;
    double root = pow(n, 1.0/4.0);
    std::cout << std::fixed << std::setprecision(1) << root << std::endl;
    return 0;
}
