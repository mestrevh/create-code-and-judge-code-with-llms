/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int celsius;
    std::cin >> celsius;
    double fahrenheit = (celsius * 9.0 / 5.0) + 32;
    std::cout << std::fixed << std::setprecision(1) << fahrenheit << std::endl;
    return 0;
}
