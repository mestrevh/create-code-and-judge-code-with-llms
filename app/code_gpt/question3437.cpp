/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

const double PI = 3.14159265358979323846;

std::vector<double> lerVetor(int n) {
    std::vector<double> vetor(n);
    for (int i = 0; i < n; i++) {
        std::cin >> vetor[i];
    }
    return vetor;
}

std::vector<double> converterGrausParaRadianos(const std::vector<double>& graus) {
    std::vector<double> radianos(graus.size());
    for (size_t i = 0; i < graus.size(); i++) {
        radianos[i] = graus[i] * (PI / 180.0);
    }
    return radianos;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<double> angulos = lerVetor(N);
    std::vector<double> radianos = converterGrausParaRadianos(angulos);
    
    for (double rad : radianos) {
        std::cout << std::fixed << std::setprecision(5) << rad << std::endl;
    }
    
    return 0;
}
