/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double deposito, total = 0;
    int metasCumpridas = 0;
    std::cin >> deposito;
    total += deposito;
    
    for (int i = 1; i < 7; i++) {
        double novoDeposito;
        std::cin >> novoDeposito;
        if (novoDeposito >= deposito + 0.50) {
            metasCumpridas++;
        }
        total += novoDeposito;
        deposito = novoDeposito;
    }
    
    std::cout << "R$ " << std::fixed << std::setprecision(2) << total << std::endl;
    std::cout << metasCumpridas << std::endl;
    return 0;
}
