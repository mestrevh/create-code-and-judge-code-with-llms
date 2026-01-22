/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double a, b;
    std::cin >> a >> b;
    double hipotenusa = sqrt(a * a + b * b);
    std::cout << std::fixed << std::setprecision(2) << hipotenusa << std::endl;
    return 0;
}
