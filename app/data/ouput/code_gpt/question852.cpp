/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <numeric>

int main() {
    int n;
    std::cin >> n;
    std::vector<double> tempos(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> tempos[i];
    }
    
    double lcm = tempos[0];
    for (int i = 1; i < n; ++i) {
        lcm = std::lcm(static_cast<int>(lcm), static_cast<int>(tempos[i]));
    }
    
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "O tempo para o alinhamento dos planetas e " << lcm << " minutos" << std::endl;

    return 0;
}
