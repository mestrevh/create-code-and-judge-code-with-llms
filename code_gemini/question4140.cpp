/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    char forma, calculo;
    const float PI = 3.1415f;

    std::cin >> forma;

    std::cout << std::fixed << std::setprecision(2);

    if (forma == 'c') {
        std::cin >> calculo;
        if (calculo == 'a') {
            float raio, altura;
            std::cin >> raio >> altura;
            float area = 2.0f * PI * raio * (raio + altura);
            std::cout << "A area do cilindro de raio " << raio << " e altura " << altura << " eh: " << area << std::endl;
        } else if (calculo == 'v') {
            float raio, altura;
            std::cin >> raio >> altura;
            float volume = PI * pow(raio, 2) * altura;
            std::cout << "O volume do cilindro de raio " << raio << " e altura " << altura << " eh: " << volume << std::endl;
        } else {
            std::cout << "Entrada invalida! Entre com 'a' (area) ou 'v' (volume)." << std::endl;
        }
    } else if (forma == 'e') {
        std::cin >> calculo;
        if (calculo == 'a') {
            float raio;
            std::cin >> raio;
            float area = 4.0f * PI * pow(raio, 2);
            std::cout << "A area da esfera de raio " << raio << " eh:" << std::endl;
            std::cout << area << std::endl;
        } else if (calculo == 'v') {
            float raio;
            std::cin >> raio;
            float volume = (4.0f / 3.0f) * PI * pow(raio, 3);
            std::cout << "O volume da esfera de raio " << raio << " eh:" << std::endl;
            std::cout << volume << std::endl;
        } else {
            std::cout << "Entrada invalida! Entre com 'a' (area) ou 'v' (volume)." << std::endl;
        }
    } else {
        std::cout << "Entrada invalida! Voce deve usar 'c' (cilindro) ou 'e' (esfera)." << std::endl;
    }

    return 0;
}
