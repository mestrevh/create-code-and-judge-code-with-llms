/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

double calcularDistancia(int x1, int y1, int x2, int y2) {
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    
    double distancia = calcularDistancia(x1, y1, x2, y2);
    
    std::cout << distancia << std::endl;
    
    return 0;
}
