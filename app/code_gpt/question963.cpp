/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<double>> matriz(n, std::vector<double>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matriz[i][j];
        }
    }
    
    int linha, coluna;
    std::cin >> linha >> coluna;
    linha--; coluna--; // Converte para 0-indexed

    std::cout << std::fixed << std::setprecision(2);
    for (int i = linha; i < linha + 2; i++) {
        for (int j = coluna; j < coluna + 2; j++) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
