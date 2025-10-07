/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    int N;
    double R;
    std::cin >> N >> R;
    
    double perimeter = N * 2 * R * sin(M_PI / N);
    std::cout << std::fixed << std::setprecision(2) << perimeter << std::endl;
    
    return 0;
}
