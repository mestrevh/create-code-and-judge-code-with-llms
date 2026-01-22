/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    double nota1, nota2;
    std::cin >> nota1 >> nota2;
    
    const double peso1 = 6.0;
    const double peso2 = 4.0;
    
    double media = (nota1 * peso1 + nota2 * peso2) / (peso1 + peso2);
    
    std::cout << "Média= " << std::fixed << std::setprecision(1) << media << std::endl;
    
    return 0;
}
