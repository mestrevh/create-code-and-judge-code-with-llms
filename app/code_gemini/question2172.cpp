/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int calcularTempo(const std::vector<int>& sequencia, int indiceAtual) {
    if (sequencia[indiceAtual] == -1) {
        return 2;
    }
    return 2 + calcularTempo(sequencia, indiceAtual + 1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> sequencia(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> sequencia[i];
    }

    int tempoTotal = calcularTempo(sequencia, 0);

    std::cout << tempoTotal << std::endl;

    return 0;
}
