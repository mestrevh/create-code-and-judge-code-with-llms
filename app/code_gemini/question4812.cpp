/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>

double calcularMediaFinal(std::vector<double> notas) {
    std::sort(notas.begin(), notas.end());
    double soma = 0.0;
    for (size_t i = 2; i < notas.size(); ++i) {
        soma += notas[i];
    }
    return soma / (notas.size() - 2);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n < 3) {
        std::cout << "Numero de notas insuficiente." << std::endl;
        return 0;
    }

    std::vector<double> notas(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> notas[i];
    }

    double media_final = calcularMediaFinal(notas);

    std::cout << std::fixed << std::setprecision(2) << media_final << std::endl;

    return 0;
}
