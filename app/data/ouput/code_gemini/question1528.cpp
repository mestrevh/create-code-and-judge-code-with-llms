/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    const double PI = 3.1416;
    double R;
    std::cin >> R;
    double volume = (4.0 / 3.0) * PI * R * R * R;
    std::cout << std::fixed << std::setprecision(2) << volume << std::endl;
    return 0;
}
