/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double hourly_rate;
    double hours_worked;

    std::cout << "Informe quanto ganha por hora:" << std::endl;
    std::cin >> hourly_rate;

    std::cout << "Informe a quantidade mensal de trabalho:" << std::endl;
    std::cin >> hours_worked;

    double salary = hourly_rate * hours_worked;

    std::cout << "Resultado: " << std::fixed << std::setprecision(1) << salary << std::endl;

    return 0;
}
