/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double A, B;
    std::cin >> A >> B;
    double media = (A * 3.5 + B * 7.5) / 11.0;
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "MEDIA = " << media << std::endl;
    return 0;
}
