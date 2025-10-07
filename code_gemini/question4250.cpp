/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    const double PI = 3.1416;
    double R;

    std::cout << "Digite o raio da esfera:" << std::endl;
    std::cin >> R;

    double area = 4.0 * PI * R * R;
    double volume = (4.0 * PI * pow(R, 3)) / 3.0;

    std::cout << std::fixed << std::setprecision(3);
    std::cout << "A area da superficie esferica e igual a " << area << std::endl;
    std::cout << "O volume da esfera e igual a " << volume << std::endl;

    return 0;
}
