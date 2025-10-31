/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double A, B, C;
    std::cin >> A >> B >> C;
    double media = (A * 2 + B * 3 + C * 5) / 10;
    std::cout << std::fixed << std::setprecision(1) << "MEDIA = " << media << std::endl;
    return 0;
}
