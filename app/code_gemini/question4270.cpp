/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string escala;
    double temperatura;

    std::cin >> escala >> temperatura;

    std::cout << std::fixed;

    if (escala == "C") {
        double fahrenheit = (temperatura * 1.8) + 32;
        double kelvin = temperatura + 273.15;
        std::cout << std::setprecision(1) << fahrenheit << " F\n";
        std::cout << std::setprecision(2) << kelvin << " K\n";
    } else if (escala == "F") {
        double celsius = (temperatura - 32) / 1.8;
        double kelvin = celsius + 273.15;
        std::cout << std::setprecision(2) << celsius << " C\n";
        std::cout << std::setprecision(2) << kelvin << " K\n";
    } else if (escala == "K") {
        double celsius = temperatura - 273.15;
        double fahrenheit = (celsius * 1.8) + 32;
        std::cout << std::setprecision(2) << celsius << " C\n";
        std::cout << std::setprecision(1) << fahrenheit << " F\n";
    }

    return 0;
}
