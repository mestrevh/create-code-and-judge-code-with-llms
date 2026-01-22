/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    char scale;
    double temp;

    std::cin >> scale >> temp;

    std::cout << std::fixed << std::setprecision(2);

    if (scale == 'C') {
        if (temp < -273.15) {
            std::cout << "Valor de temperatura abaixo do minimo\n";
        } else {
            double fahrenheit = temp * 9.0 / 5.0 + 32.0;
            double kelvin = temp + 273.15;
            std::cout << fahrenheit << " F\n";
            std::cout << kelvin << " K\n";
        }
    } else if (scale == 'F') {
        if (temp < -459.67) {
            std::cout << "Valor de temperatura abaixo do minimo\n";
        } else {
            double celsius = (temp - 32.0) * 5.0 / 9.0;
            double kelvin = celsius + 273.15;
            std::cout << celsius << " C\n";
            std::cout << kelvin << " K\n";
        }
    } else if (scale == 'K') {
        if (temp < 0.0) {
            std::cout << "Valor de temperatura abaixo do minimo\n";
        } else {
            double celsius = temp - 273.15;
            double fahrenheit = celsius * 9.0 / 5.0 + 32.0;
            std::cout << celsius << " C\n";
            std::cout << fahrenheit << " F\n";
        }
    }

    return 0;
}
