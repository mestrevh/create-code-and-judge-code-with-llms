/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double R;
    std::cin >> R;
    double volume = (4.0 / 3.0) * 3.1416 * pow(R, 3);
    std::cout << std::fixed << std::setprecision(2) << volume << std::endl;
    return 0;
}
