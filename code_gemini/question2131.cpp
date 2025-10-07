/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int P, E;
    std::cin >> P >> E;

    std::vector<std::vector<int>> votos(E, std::vector<int>(P));

    for (int i = 0; i < E; ++i) {
        for (int j = 0; j < P; ++j) {
            std::cin >> votos[i][j];
        }
    }

    for (int j = 0; j < P; ++j) {
        int totalVotos = 0;
        for (int i = 0; i < E; ++i) {
            totalVotos += votos[i][j];
        }
        std::cout << "Princesa " << j + 1 << ": " << totalVotos << " voto(s)\n";
    }

    return 0;
}
