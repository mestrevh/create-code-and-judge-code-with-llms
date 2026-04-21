/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double fahrenheit;
    if (std::cin >> fahrenheit) {
        double celsius = (5.0 * (fahrenheit - 32.0)) / 9.0;
        
        std::cout << "Digite uma temperatura na escala Fahrenheit:" << "\n";
        std::cout << "Temperatura em Celsius: " << std::fixed << std::setprecision(1) << celsius << "\n";
    }

    return 0;
}