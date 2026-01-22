/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

double calcularTermo(int n) {
    return sqrt(n) * pow(2, n);
}

double somaSerie(int N, std::vector<double>& termos) {
    double soma = 0;
    for (int i = 0; i < N; ++i) {
        termos.push_back(calcularTermo(i));
        soma += termos[i];
    }
    return soma;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<double> termos;
    double soma = somaSerie(N, termos);
    
    std::cout << std::fixed << std::setprecision(12) << "S: " << soma << std::endl;
    for (int i = termos.size() - 1; i >= 0; --i) {
        std::cout << termos[i] << std::endl;
    }
    
    return 0;
}
