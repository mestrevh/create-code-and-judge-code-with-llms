/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    std::vector<int> numeros(10);
    int somaDivisiveis = 0;
    
    for (int i = 0; i < 10; ++i) {
        std::cin >> numeros[i];
    }
    
    double somaTotal = 0;
    for (int num : numeros) {
        somaTotal += num;
        if (num % 3 == 0) {
            somaDivisiveis += num;
        }
    }
    
    double media = somaTotal / 10;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Média: " << media << std::endl;
    std::cout << "Divisíveis: " << somaDivisiveis << std::endl;

    return 0;
}
