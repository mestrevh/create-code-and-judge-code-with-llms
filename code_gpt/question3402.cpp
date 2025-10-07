/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double A, B, C, D;
    std::cin >> A >> B >> C >> D;
    
    if (A == C) {
        std::cout << "As retas são paralelas." << std::endl;
        return 0;
    }

    double x = (D - B) / (A - C);
    double y = A * x + B;

    std::cout << std::fixed << std::setprecision(2) << x << " " << y << std::endl;

    return 0;
}
