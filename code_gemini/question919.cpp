/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double saldo_inicial, total_debitos, total_creditos, saldo_final;

    std::cout << "Informe o saldo inicial do cliente:" << std::endl;
    std::cin >> saldo_inicial;

    std::cout << "Informe o total de debitos adquiridos pelo cliente:" << std::endl;
    std::cin >> total_debitos;

    std::cout << "Informe o total de creditos adquiridos pelo cliente:" << std::endl;
    std::cin >> total_creditos;

    saldo_final = saldo_inicial - total_debitos + total_creditos;

    std::cout << std::fixed << std::setprecision(15);

    if (saldo_final > 0) {
        std::cout << "Saldo positivo em R$ " << saldo_final << std::endl;
    } else if (saldo_final < 0) {
        std::cout << "Saldo negativo em R$ " << saldo_final << std::endl;
    } else {
        std::cout << "Saldo Zero" << std::endl;
    }

    return 0;
}
