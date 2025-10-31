/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double Ri, Re;
    std::cin >> Ri >> Re;
    double area = M_PI * (Re * Re - Ri * Ri);
    std::cout << std::fixed << std::setprecision(2) << area << std::endl;
    return 0;
}
