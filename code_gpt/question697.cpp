/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int A, B, C, D, E, F;
    std::cin >> A >> B >> C >> D >> E >> F;
    
    double x = (C*E - B*F) / (A*E - B*D);
    double y = (C - A*x) / B;

    std::cout << std::fixed << std::setprecision(2) << x << std::endl;
    std::cout << std::fixed << std::setprecision(2) << y << std::endl;

    return 0;
}
