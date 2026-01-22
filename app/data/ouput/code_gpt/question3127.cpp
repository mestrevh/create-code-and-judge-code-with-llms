/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    float theta, v, g;
    std::cin >> theta >> v >> g;

    theta = theta * M_PI / 180; // Convertendo graus para radianos
    float h = (v * v * sin(theta) * sin(theta)) / (2 * g);

    std::cout << h << std::endl;

    return 0;
}
