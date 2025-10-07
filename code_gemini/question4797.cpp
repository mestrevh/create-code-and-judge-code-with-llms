/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    char c;
    int i;
    float f1;
    double d;
    std::cin >> c >> i >> f1 >> d;
    std::cout << std::fixed << std::setprecision(2) << d << " " << f1 << " " << i << " " << c << std::endl;
    return 0;
}
