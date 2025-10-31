/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double kwh;
    
    std::cout << "Digite o valor real em KWh consumido:" << std::endl;
    std::cin >> kwh;
    
    double valor_total = kwh * 1.50;
    double valor_desconto = valor_total * 0.85;
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Valor a ser pago: R$ " << valor_total << " reais" << std::endl;
    std::cout << "Valor a ser pago com desconto: R$ " << valor_desconto << " reais" << std::endl;
    
    return 0;
}
