/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double R, H;
    std::cin >> R >> H;
    double volume = M_PI * R * R * H;
    std::cout << std::fixed << std::setprecision(2) << volume << std::endl;
    return 0;
}
