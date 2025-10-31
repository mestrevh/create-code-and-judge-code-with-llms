/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    float xA, yA, xB, yB;
    std::cin >> xA >> yA >> xB >> yB;
    float distance = sqrt(pow(xB - xA, 2) + pow(yB - yA, 2));
    std::cout << std::fixed << std::setprecision(1) << distance << std::endl;
    return 0;
}
