/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string scale;
    double temp;

    std::cin >> scale >> temp;

    if (scale == "C") {
        double fahrenheit = temp * 1.8 + 32.0;
        double kelvin = temp + 273.15;
        std::cout << std::fixed << std::setprecision(1) << fahrenheit << " F\n";
        std::cout << std::fixed << std::setprecision(2) << kelvin << " K\n";
    } else if (scale == "K") {
        double celsius = temp - 273.15;
        double fahrenheit = celsius * 1.8 + 32.0;
        std::cout << std::fixed << std::setprecision(2) << celsius << " C\n";
        std::cout << std::fixed << std::setprecision(1) << fahrenheit << " F\n";
    } else if (scale == "F") {
        double celsius = (temp - 32.0) / 1.8;
        double kelvin = celsius + 273.15;
        std::cout << std::fixed << std::setprecision(2) << celsius << " C\n";
        std::cout << std::fixed << std::setprecision(2) << kelvin << " K\n";
    }

    return 0;
}
