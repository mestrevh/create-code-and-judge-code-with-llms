/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    double a, b;
    std::cin >> a >> b;
    int hipotenusa = static_cast<int>(std::sqrt(a * a + b * b));
    std::cout << hipotenusa << std::endl;
    return 0;
}
