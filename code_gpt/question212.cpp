/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main() {
    std::vector<double> notas(5);
    for (int i = 0; i < 5; ++i) {
        std::cin >> notas[i];
    }
    std::sort(notas.begin(), notas.end());
    double soma = notas[1] + notas[2] + notas[3];
    std::cout << std::fixed << std::setprecision(1) << soma << std::endl;
    return 0;
}
