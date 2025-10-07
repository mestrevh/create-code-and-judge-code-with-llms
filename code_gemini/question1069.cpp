/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    char forma;
    std::cin >> forma;

    std::cout << std::fixed << std::setprecision(2);

    if (forma == 'Q') {
        double lado;
        std::cin >> lado;
        double area = lado * lado;
        double perimetro = 4 * lado;
        std::cout << area << std::endl;
        std::cout << perimetro << std::endl;
    } else if (forma == 'R') {
        double largura, altura;
        std::cin >> largura >> altura;
        double area = largura * altura;
        double perimetro = 2 * (largura + altura);
        std::cout << area << std::endl;
        std::cout << perimetro << std::endl;
    } else if (forma == 'C') {
        const double PI = 3.14;
        double raio;
        std::cin >> raio;
        double area = PI * raio * raio;
        double comprimento = 2 * PI * raio;
        std::cout << area << std::endl;
        std::cout << comprimento << std::endl;
    } else {
        std::cout << "Nenhuma figura selecionada" << std::endl;
    }

    return 0;
}
