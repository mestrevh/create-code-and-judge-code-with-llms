/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

double somar(double a, double b) {
    return a + b;
}

int main() {
    double a, b;
    std::cin >> a >> b;

    double resultado = somar(a, b);
    std::cout << std::fixed << std::setprecision(1);
    
    if (resultado == static_cast<int>(resultado)) {
        std::cout << "O resultado de " << std::fixed << std::setprecision(1) << a << " + " << std::fixed << std::setprecision(1) << b << " eh " << static_cast<int>(resultado) << std::endl;
    } else {
        std::cout << "O resultado de " << std::fixed << std::setprecision(1) << a << " + " << std::fixed << std::setprecision(1) << b << " eh " << resultado << std::endl;
    }
    
    return 0;
}
