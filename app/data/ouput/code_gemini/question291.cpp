/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double R;
    double pi = 3.14159;
    std::cin >> R;
    double volume = (4.0 / 3.0) * pi * R * R * R;
    std::cout << "VOLUME = " << std::fixed << std::setprecision(3) << volume << std::endl;
    return 0;
}
