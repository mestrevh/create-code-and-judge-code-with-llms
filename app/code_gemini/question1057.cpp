/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double cateto1, cateto2;
    std::cin >> cateto1 >> cateto2;
    double hipotenusa_quadrado = cateto1 * cateto1 + cateto2 * cateto2;
    double hipotenusa = std::sqrt(hipotenusa_quadrado);
    std::cout << std::fixed << std::setprecision(2) << hipotenusa << std::endl;
    return 0;
}
