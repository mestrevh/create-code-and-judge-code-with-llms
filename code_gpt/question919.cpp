/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double saldoInicial, debitos, creditos;
    
    std::cout << "Informe o saldo inicial do cliente:\n";
    std::cin >> saldoInicial;
    
    std::cout << "Informe o total de debitos adquiridos pelo cliente:\n";
    std::cin >> debitos;
    
    std::cout << "Informe o total de creditos adquiridos pelo cliente:\n";
    std::cin >> creditos;

    double saldoFinal = saldoInicial - debitos + creditos;

    std::cout << std::fixed << std::setprecision(2);
    if (saldoFinal > 0) {
        std::cout << "Saldo positivo em R$ " << saldoFinal << std::endl;
    } else if (saldoFinal < 0) {
        std::cout << "Saldo negativo em R$ " << saldoFinal << std::endl;
    } else {
        std::cout << "Saldo Zero" << std::endl;
    }

    return 0;
}
