/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    int N;
    while (std::cin >> N && N != 0) {
        std::vector<int> varetas(10001, 0);
        for (int i = 0; i < N; ++i) {
            int C, V;
            std::cin >> C >> V;
            varetas[C] += V;
        }
        int retangulos = 0;
        int pares = 0;
        
        for (int comprimento = 1; comprimento <= 10000; ++comprimento) {
            pares += varetas[comprimento] / 2;
        }
        retangulos = pares / 2;
        
        std::cout << retangulos << std::endl;
    }
    return 0;
}
