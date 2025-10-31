/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int gallons;
    std::cin >> gallons;

    double liters = gallons * 3.7854;

    std::cout << gallons << " GALÕES -> " 
              << std::fixed << std::setprecision(2) 
              << liters << " LITROS" << std::endl;

    return 0;
}
