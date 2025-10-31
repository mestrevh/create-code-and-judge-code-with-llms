/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::vector<double> notas(5);
    for (int i = 0; i < 5; ++i) {
        std::cin >> notas[i];
    }
    std::sort(notas.begin(), notas.end());
    double nota_final = notas[1] + notas[2] + notas[3];
    std::cout << std::fixed << std::setprecision(1) << nota_final << std::endl;
    return 0;
}
