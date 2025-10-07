/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Jogo {
    int nota;
    double preco;
};

bool comparar(const Jogo &a, const Jogo &b) {
    if (a.nota != b.nota) return a.nota > b.nota;
    return a.preco < b.preco;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<Jogo> jogos(N);

    for (int i = 0; i < N; ++i) {
        std::cin >> jogos[i].nota >> jogos[i].preco;
    }

    std::sort(jogos.begin(), jogos.end(), comparar);

    for (const auto &jogo : jogos) {
        std::cout << "Nota: " << jogo.nota << std::endl;
        std::cout << "Preco: " << std::fixed << std::setprecision(2) << jogo.preco << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
