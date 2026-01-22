/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double fahrenheit;

    std::cout << "Digite uma temperatura na escala Fahrenheit:" << std::endl;
    
    std::cin >> fahrenheit;

    double celsius = (5.0 * (fahrenheit - 32.0)) / 9.0;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Temperatura em Celsius: " << celsius << std::endl;

    return 0;
}
