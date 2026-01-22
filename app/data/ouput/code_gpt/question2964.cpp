/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double a, b, c, d;
    std::cin >> a >> b >> c >> d;

    std::cout << std::fixed << std::setprecision(4);
    
    std::cout << "i) " << round(a*b + c*d) << "\n";
    std::cout << "ii) " << round(a*b*c - d) << "\n";
    std::cout << "iii) " << round(log(a + b + c + d)) << "\n";
    std::cout << "iv) " << round(pow(a, b) / d) << "\n";
    std::cout << "v) " << round((a + b + c) / d) << "\n";
    std::cout << "vi) " << round(a * b * c * d) << "\n";
    std::cout << "vii) " << round((a + b) * (c - d)) << "\n";
    std::cout << "viii) " << round(sqrt(a) + sqrt(b)) << "\n";

    return 0;
}
