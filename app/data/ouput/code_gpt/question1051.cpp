/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    float raio;
    std::cin >> raio;
    if (raio < 1.0 || raio > 50.0) return 0;
    
    float volume = (4.0 / 3.0) * 3.14 * std::pow(raio, 3);
    std::cout << std::fixed << std::setprecision(2) << volume << std::endl;
    
    return 0;
}
