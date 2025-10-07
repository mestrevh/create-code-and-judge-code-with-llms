/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double fahrenheit;
    std::cin >> fahrenheit;

    double celsius = (fahrenheit - 32) * 5.0 / 9.0;
    double kelvin = celsius + 273.15;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Convertendo " << fahrenheit << " graus Fahrenheit temos:\n";
    std::cout << celsius << " graus Celsius e " << kelvin << " Kelvin\n";

    return 0;
}
