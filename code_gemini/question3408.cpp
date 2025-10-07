/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    double salario;
    std::cin >> salario;
    
    double novo_salario = salario;
    
    if (salario <= 5000.00) {
        novo_salario += salario * 0.05;
    } else if (salario > 5000.00 && salario <= 12000.00) {
        novo_salario += salario * 0.12;
    }
    
    if (salario <= 6000.00) {
        novo_salario += 150.00;
    } else {
        novo_salario += 100.00;
    }
    
    std::cout << std::fixed << std::setprecision(2) << novo_salario << std::endl;
    
    return 0;
}
