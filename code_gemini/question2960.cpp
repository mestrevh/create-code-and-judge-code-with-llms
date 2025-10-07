/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double t_fahrenheit;
    std::cin >> t_fahrenheit;

    double t_celsius = (t_fahrenheit - 32.0) * 5.0 / 9.0;
    double t_kelvin = t_celsius + 273.15;

    std::cout << std::fixed;
    
    std::cout << "Convertendo " << std::setprecision(1) << t_fahrenheit << " graus Fahrenheit temos:" << std::endl;
    std::cout << std::setprecision(1) << t_celsius << " graus Celsius e " << std::setprecision(2) << t_kelvin << " Kelvin" << std::endl;

    return 0;
}
