/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    double n;
    std::cin >> n;
    double e = exp(1);
    double pi = M_PI;

    std::cout << "i) " << n * n << std::endl;
    std::cout << "ii) " << n * e << std::endl;
    std::cout << "iii) " << sqrt(n) << std::endl;
    std::cout << "iv) " << pow(n, 1.0/3) << std::endl;
    std::cout << "v) " << pow(n, 0.5) << std::endl;
    std::cout << "vi) " << n * log(n) << std::endl;
    std::cout << "vii) " << pi / n << std::endl;
    std::cout << "viii) " << log10(n) << std::endl;
    std::cout << "ix) " << log(n) << std::endl;
    std::cout << "x) " << log(n + 1) << std::endl;

    return 0;
}
