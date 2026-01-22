/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double n1, n2, n3, n4;
    std::cin >> n1 >> n2 >> n3 >> n4;
    double media = (n1 * 2 + n2 * 2 + n3 * 3 + n4 * 3) / 10;
    std::cout << std::fixed << std::setprecision(2) << "A média ponderada será: " << media << std::endl;
    return 0;
}
