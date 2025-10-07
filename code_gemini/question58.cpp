/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

struct Pais {
    int id;
    int ouro;
    int prata;
    int bronze;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    std::vector<Pais> paises(N);
    for (int i = 0; i < N; ++i) {
        paises[i].id = i + 1;
        paises[i].ouro = 0;
        paises[i].prata = 0;
        paises[i].bronze = 0;
    }

    for (int i = 0; i < M; ++i) {
        int o, p, b;
        std::cin >> o >> p >> b;
        paises[o - 1].ouro++;
        paises[p - 1].prata++;
        paises[b - 1].bronze++;
    }

    std::sort(paises.begin(), paises.end(), [](const Pais& a, const Pais& b) {
        if (a.ouro != b.ouro) {
            return a.ouro > b.ouro;
        }
        if (a.prata != b.prata) {
            return a.prata > b.prata;
        }
        if (a.bronze != b.bronze) {
            return a.bronze > b.bronze;
        }
        return a.id < b.id;
    });

    for (const auto& pais : paises) {
        std::cout << pais.id << "\n";
    }

    return 0;
}
