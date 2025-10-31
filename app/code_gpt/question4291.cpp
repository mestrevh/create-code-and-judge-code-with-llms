/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;
    double soma = 0.0;
    
    for (int i = 0; i < n; ++i) {
        double nota;
        std::cin >> nota;
        soma += nota;
    }
    
    double media = soma / n;
    std::cout << std::fixed << std::setprecision(10) << media << std::endl;
    
    return 0;
}
