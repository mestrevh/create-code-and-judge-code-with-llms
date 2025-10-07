/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double cateto1, cateto2;
    std::cin >> cateto1 >> cateto2;
    double hipotenusa_quadrado = (cateto1 * cateto1) + (cateto2 * cateto2);
    double hipotenusa = std::sqrt(hipotenusa_quadrado);
    std::cout << static_cast<int>(hipotenusa) << std::endl;
    return 0;
}
