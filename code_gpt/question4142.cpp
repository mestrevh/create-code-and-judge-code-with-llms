/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double distancia;
    std::cin >> distancia;
    
    double velocidade_inicial = 400.0; // km/h
    double velocidade_final = 0.0; // km/h

    // Convertendo velocidades de km/h para m/s
    velocidade_inicial = velocidade_inicial * (1000.0 / 3600.0);
    velocidade_final = velocidade_final * (1000.0 / 3600.0);

    // Usando a fórmula de movimento uniformemente variado: v^2 = u^2 + 2*a*s
    // onde v = velocidade final, u = velocidade inicial, a = aceleração, s = distância
    double aceleracao = (velocidade_final * velocidade_final - velocidade_inicial * velocidade_inicial) / (2 * distancia);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "A desaceleracao desse veiculo foi de aproximadamente: " << aceleracao << " m/s^2" << std::endl;

    return 0;
}
