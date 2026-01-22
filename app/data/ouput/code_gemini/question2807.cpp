/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int dias;
    int km;
    
    std::cin >> dias;
    std::cin >> km;
    
    double valor_dias = dias * 30.00;
    double valor_km = km * 0.01;
    double total_bruto = valor_dias + valor_km;
    double valor_final = total_bruto * 0.90;
    
    std::cout << "Digite a quantidade de dias de locacao:" << std::endl;
    std::cout << "Digite a quantidade de km rodados:" << std::endl;
    
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Valor a pagar pelo aluguel: R$ " << valor_final << std::endl;
    
    return 0;
}
