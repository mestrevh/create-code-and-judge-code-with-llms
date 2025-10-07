/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#ifndef M_E
#define M_E 2.71828182845904523536
#endif

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double n;
    std::cin >> n;

    std::cout << std::fixed << std::setprecision(16);

    std::cout << "i) " << pow(n, 2) << std::endl;
    std::cout << "ii) " << pow(n, M_E) << std::endl;
    std::cout << "iii) " << sqrt(n) << std::endl;
    std::cout << "iv) " << cbrt(n) << std::endl;
    std::cout << "v) " << pow(n, 1.0 / n) << std::endl;
    std::cout << "vi) " << n * M_E << std::endl;
    std::cout << "vii) " << M_PI / n << std::endl;
    std::cout << "viii) " << log(n) / log(7.0) << std::endl;
    std::cout << "ix) " << log(n) << std::endl;
    std::cout << "x) " << log(n) / log(M_PI) << std::endl;

    return 0;
}
