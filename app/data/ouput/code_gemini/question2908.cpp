/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

struct Cavaleiro {
    std::string nome;
    int pontuacao;
};

bool comparaCavaleiros(const Cavaleiro& a, const Cavaleiro& b) {
    if (a.pontuacao != b.pontuacao) {
        return a.pontuacao > b.pontuacao;
    }
    return a.nome < b.nome;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::map<std::string, int> pontuacoes;
    pontuacoes["Shun"] = 0;
    pontuacoes["Hyoga"] = 0;
    pontuacoes["Seiya"] = 0;
    pontuacoes["Shiryu"] = 0;
    pontuacoes["Ikki"] = 0;

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::string cav1, cav2, vencedor;
        std::cin >> cav1 >> cav2 >> vencedor;

        pontuacoes[vencedor] += 3;

        if (vencedor == cav1) {
            pontuacoes[cav2] -= 1;
        } else {
            pontuacoes[cav1] -= 1;
        }
    }

    std::vector<Cavaleiro> ranking;
    for (const auto& par : pontuacoes) {
        ranking.push_back({par.first, par.second});
    }

    std::sort(ranking.begin(), ranking.end(), comparaCavaleiros);

    for (int i = 0; i < 3; ++i) {
        std::cout << ranking[i].nome << " " << ranking[i].pontuacao << "\n";
    }

    return 0;
}
