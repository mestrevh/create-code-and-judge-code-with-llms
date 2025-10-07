/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double impulso, altura, distancia, peso;
    std::string yoshi;

    std::cin >> impulso >> altura >> distancia >> peso >> yoshi;

    if (yoshi == "Sim") {
        impulso += 5;
        peso += 50;
    }

    double numerador = pow(impulso, 3);
    double denominador = sqrt(altura) + (distancia / 2.0) + (peso / 3.0);
    
    double altura_salto = 0;
    if (denominador != 0) {
        altura_salto = numerador / denominador;
    }

    if (altura_salto >= 100) {
        std::cout << "Voce consegue" << std::endl;
    } else {
        std::cout << "Isso e perda de tempo" << std::endl;
    }

    return 0;
}
