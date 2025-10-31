/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double A, B, C;
    std::cin >> A >> B >> C;
    double media = (A * 2 + B * 3 + C * 5) / 10.0;
    std::cout << "MEDIA = " << std::fixed << std::setprecision(1) << media << std::endl;
    return 0;
}
