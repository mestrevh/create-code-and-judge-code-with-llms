/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double fahrenheit;
    std::cin >> fahrenheit;
    double celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
    std::cout << std::fixed << std::setprecision(2) << celsius << std::endl;
    return 0;
}
