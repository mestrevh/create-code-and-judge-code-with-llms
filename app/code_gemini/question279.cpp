/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int numero_funcionario, horas_trabalhadas;
    double valor_por_hora;

    std::cin >> numero_funcionario;
    std::cin >> horas_trabalhadas;
    std::cin >> valor_por_hora;

    double salario = horas_trabalhadas * valor_por_hora;

    std::cout << "NUMBER = " << numero_funcionario << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "SALARY = R$ " << salario << std::endl;

    return 0;
}
