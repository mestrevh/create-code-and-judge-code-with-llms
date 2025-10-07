/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    double a, b;
    int c, d;
    std::cin >> a >> b >> c >> d;
    double maior_lado = std::max(c, d);
    if (maior_lado <= a * b) {
        std::cout << "Pousa, bilu" << std::endl;
    } else {
        std::cout << "Procura outro lugar, bilu" << std::endl;
    }
    return 0;
}
