/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int angulo1, angulo2;
    std::cin >> angulo1 >> angulo2;

    int angulo3 = 180 - angulo1 - angulo2;

    std::cout << "3o angulo=" << std::fixed << std::setprecision(6) << static_cast<double>(angulo3) << std::endl;

    return 0;
}
