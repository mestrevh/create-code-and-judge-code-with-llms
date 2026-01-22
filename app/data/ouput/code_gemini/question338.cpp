/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double n;
    std::cin >> n;

    double n_a = trunc(n * 100.0) / 100.0;
    std::cout << "|" << std::fixed << std::setprecision(2) << n_a << "|" << std::endl;

    double n_b = trunc(n * 100000.0) / 100000.0;
    std::cout << "|" << std::fixed << std::setprecision(5) << n_b << "|" << std::endl;

    double n_cd = trunc(n * 10.0) / 10.0;
    std::cout << "|      " << std::fixed << std::setprecision(1) << n_cd << "|" << std::endl;
    
    std::cout << "|" << std::fixed << std::setprecision(1) << n_cd << "      |" << std::endl;

    return 0;
}
