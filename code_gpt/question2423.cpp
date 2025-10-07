/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <tuple>

int main() {
    int N, M, T[3], V[3];
    std::cin >> N >> M;
    for (int i = 0; i < 3; ++i) {
        std::cin >> T[i] >> V[i];
    }

    double ideal = (N - 1) / 2.0;
    if (ideal > M) {
        std::cout << "Não cantarei, desculpa." << std::endl;
        return 0;
    }

    double min_vergonha = 1e9;
    int musica_escolhida = -1;
    
    for (int i = 0; i < 3; ++i) {
        double vergonha = (T[i] / 60.0) * V[i];
        if (vergonha < min_vergonha) {
            min_vergonha = vergonha;
            musica_escolhida = i + 1;
        }
    }

    std::cout << "Você deve cantar a música " << musica_escolhida << ", boa sorte!" << std::endl;
    return 0;
}
