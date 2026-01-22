/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    int N;
    std::cin >> N;
    if (N == 0) {
        std::cout << "Nenhuma nota informada!" << std::endl;
        return 0;
    }
    
    std::vector<double> notas(N);
    double soma = 0.0;
    
    for (int i = 0; i < N; ++i) {
        std::cin >> notas[i];
        soma += notas[i];
    }
    
    std::cout << "[";
    for (int i = 0; i < N; ++i) {
        std::cout << std::fixed << std::setprecision(1) << notas[i];
        if (i < N - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
    std::cout << std::fixed << std::setprecision(2) << soma << std::endl;

    return 0;
}
