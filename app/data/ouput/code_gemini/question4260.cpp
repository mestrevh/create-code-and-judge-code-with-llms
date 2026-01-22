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

    double cateto1, cateto2;
    std::cin >> cateto1 >> cateto2;

    double hipotenusa_quadrada = (cateto1 * cateto1) + (cateto2 * cateto2);
    double hipotenusa = std::sqrt(hipotenusa_quadrada);

    int resultado = static_cast<int>(round(hipotenusa));

    std::cout << resultado << std::endl;

    return 0;
}
