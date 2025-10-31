/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double A, B;
    std::cin >> A >> B;
    double MEDIA = (A * 3.5 + B * 7.5) / 11;
    std::cout << std::fixed << std::setprecision(5) << "MEDIA = " << MEDIA << std::endl;
    return 0;
}
