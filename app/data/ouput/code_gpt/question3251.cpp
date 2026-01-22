/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double A, B, C, D, E;
    std::cin >> A >> B >> C >> D >> E;
    double resultado = (A + B + C) / (D + E);
    std::cout << std::fixed << std::setprecision(2) << resultado << std::endl;
    return 0;
}
