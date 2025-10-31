/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double v1, v2, v3, v4;
    std::cin >> v1 >> v2 >> v3 >> v4;
    double media = (v1 + v2 + v3 + v4) / 4.0;
    std::cout << "A media das alturas eh: " << std::fixed << std::setprecision(2) << media << std::endl;
    return 0;
}
