/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double total_premio;
    
    std::cout << "Digite o valor total do premio em dinheiro:" << std::endl;
    std::cin >> total_premio;
    
    double premio1 = total_premio * 0.6;
    double premio2 = total_premio * 0.3;
    double premio3 = total_premio * 0.1;
    
    std::cout << "Premio para o 1 lugar: R$ " << premio1 << std::endl;
    std::cout << "Premio para o 2 lugar: R$ " << premio2 << std::endl;
    std::cout << "Premio para o 3 lugar: R$ " << premio3 << std::endl;
    
    return 0;
}
