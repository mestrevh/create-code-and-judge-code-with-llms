/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double salario;
    std::cin >> salario;
    
    double aumento;
    if (salario <= 280.00) {
        aumento = 0.20;
    } else if (salario <= 700.00) {
        aumento = 0.15;
    } else if (salario <= 1500.00) {
        aumento = 0.10;
    } else {
        aumento = 0.05;
    }
    
    double salario_reajustado = salario + (salario * aumento);
    std::cout << std::fixed << std::setprecision(2) << salario_reajustado << std::endl;
    
    return 0;
}
