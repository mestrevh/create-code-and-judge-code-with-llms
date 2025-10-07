/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double angulo_graus, distancia;
    std::cin >> angulo_graus;
    std::cin >> distancia;
    
    const double PI = acos(-1.0);
    double angulo_radianos = angulo_graus * PI / 180.0;
    
    double medida_escada = distancia / cos(angulo_radianos);
    
    std::cout << std::fixed << std::setprecision(15) << medida_escada << std::endl;
    
    return 0;
}
