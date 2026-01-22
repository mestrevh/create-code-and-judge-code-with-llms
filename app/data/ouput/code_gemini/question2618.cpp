/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

struct Jogo {
    int nota;
    double preco;
};

bool compararJogos(const Jogo& a, const Jogo& b) {
    if (a.nota != b.nota) {
        return a.nota > b.nota;
    }
    return a.preco < b.preco;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Jogo> jogos(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> jogos[i].nota >> jogos[i].preco;
    }

    std::sort(jogos.begin(), jogos.end(), compararJogos);

    for (size_t i = 0; i < jogos.size(); ++i) {
        std::cout << "Nota: " << jogos[i].nota << '\n';
        std::cout << "Preco: " << std::fixed << std::setprecision(2) << jogos[i].preco << '\n';
        if (i < jogos.size() - 1) {
            std::cout << '\n';
        }
    }

    return 0;
}
