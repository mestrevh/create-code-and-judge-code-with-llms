/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int quantl, quantf, tameq, numb;
    std::cin >> quantl >> quantf >> tameq >> numb;
    double eficiencia = (static_cast<double>(quantl) / quantf) / tameq - 4.2 * numb;
    std::cout << std::fixed << std::setprecision(1) << eficiencia << std::endl;
    return 0;
}
