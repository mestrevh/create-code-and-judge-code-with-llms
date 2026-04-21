/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double n;
    if (std::cin >> n) {
        std::cout << std::fixed << std::setprecision(1) << std::sqrt(std::sqrt(n)) << std::endl;
    }
    return 0;
}