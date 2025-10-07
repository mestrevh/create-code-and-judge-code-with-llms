/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int contarPares(const std::vector<std::vector<int>>& matriz) {
    int contagem = 0;
    for (const auto& linha : matriz) {
        for (int num : linha) {
            if (num % 2 == 0) contagem++;
        }
    }
    return contagem;
}

int main() {
    int L, C;
    std::cin >> L >> C;
    std::vector<std::vector<int>> matriz(L, std::vector<int>(C));
    
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            std::cin >> matriz[i][j];
        }
    }
    
    std::cout << contarPares(matriz) << std::endl;
    return 0;
}
