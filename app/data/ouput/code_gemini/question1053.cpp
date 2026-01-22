/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    const double PI = 3.14;
    double altura, raio;

    std::cin >> altura >> raio;

    double volume = PI * raio * raio * altura;
    double area = 2 * PI * raio * (raio + altura);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << volume << std::endl;
    std::cout << area << std::endl;

    return 0;
}
