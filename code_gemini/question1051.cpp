/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    double raio;
    const double PI = 3.14;
    
    std::cin >> raio;
    
    double volume = (4.0 / 3.0) * PI * pow(raio, 3);
    
    std::cout << std::fixed << std::setprecision(2) << volume << std::endl;
    
    return 0;
}
