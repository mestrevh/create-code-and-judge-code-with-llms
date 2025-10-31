/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int angulo1, angulo2;
    std::cin >> angulo1 >> angulo2;
    double angulo3 = 180 - (angulo1 + angulo2);
    std::cout << std::fixed << std::setprecision(6) << "3o angulo=" << angulo3 << std::endl;
    return 0;
}
