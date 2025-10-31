/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double cateto1, cateto2;

    std::cout << "Digite o valor do primeiro cateto:" << std::endl;
    std::cin >> cateto1;

    std::cout << "Digite o valor do segundo cateto:" << std::endl;
    std::cin >> cateto2;

    if (cateto1 > 0 && cateto2 > 0) {
        double hipotenusa = std::sqrt(cateto1 * cateto1 + cateto2 * cateto2);
        
        // This part handles the specific output formatting from the examples.
        // It removes trailing zeros for integer-like results but keeps precision for floats.
        std::cout << "O triangulo cujos catetos sao ";
        std::cout << std::fixed << std::setprecision(15); // High precision to check
        if (cateto1 == static_cast<long long>(cateto1)) {
             std::cout << static_cast<long long>(cateto1);
        } else {
             std::cout << cateto1;
        }
        std::cout << " e ";
        if (cateto2 == static_cast<long long>(cateto2)) {
             std::cout << static_cast<long long>(cateto2);
        } else {
             std::cout << cateto2;
        }
        std::cout << " tem hipotenusa ";
        if (hipotenusa == static_cast<long long>(hipotenusa)) {
             std::cout << static_cast<long long>(hipotenusa);
        } else {
            // Revert to default float formatting for hypotenuse which matches the example's precision
            std::cout.unsetf(std::ios_base::floatfield); 
            std::cout << hipotenusa;
        }
        std::cout << "." << std::endl;

    } else {
        std::cout << "Valor de cateto invalido." << std::endl;
    }

    return 0;
}
