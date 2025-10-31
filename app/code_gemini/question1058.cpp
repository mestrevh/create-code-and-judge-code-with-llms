/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    const double R = 8.31;
    double temperatura, massa_molar;
    
    std::cin >> temperatura;
    std::cin >> massa_molar;
    
    double velocidade = std::sqrt((3 * R * temperatura) / massa_molar);
    
    std::cout << std::fixed << std::setprecision(2) << velocidade << std::endl;
    
    return 0;
}
